//
// Author : DX, 2018/9/18
//

#pragma once

#ifndef JEXER_EXCEPTION_H
#define JEXER_EXCEPTION_H

#include "JexerPrerequisites.h"

#include <exception>

#include <boost/exception/all.hpp>

namespace Jexer
{
	typedef boost::error_info<struct ErrorStr, STLStr> ErrorStr;
	typedef boost::error_info<struct ErrorInt, int>    ErrorInt;

	/**
		�쳣�������ڲ����쳣����������Ϣ
	*/
	template<typename ErrorInfo, typename ErrorValue>
	struct JexerException : virtual std::exception, virtual boost::exception
	{
		typedef ErrorInfo ErrorInfoType;
	};

	// IO�쳣
	struct JexerIOException : virtual JexerException<ErrorStr, typename ErrorStr::value_type>
	{

	};

	template<typename T>
	struct ExceptionTraits
	{
		typedef typename T::ErrorInfoType  ErrorInfoType;
	};
	
	// ��ȡ�쳣������Ϣ
	template<typename E>
	typename ExceptionTraits<E>::ErrorValue
		GetErrorInfo(E& e)
	{
		return boost::get_error_info<typename ExceptionTraits<E>::ErrorInfoType>(e);
	}

} // namespace Jexer

#endif // JEXER_EXCEPTION_H
