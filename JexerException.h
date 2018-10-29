//
// Author : DX, 2018/9/18
//

#pragma once

#ifndef JEXER_EXCEPTION_H
#define JEXER_EXCEPTION_H

#include "JexerPrerequisites.h"

#include <exception>
#include <iostream>

#include <boost/exception/all.hpp>
#include <boost/exception/info_tuple.hpp>

namespace Jexer
{
	/*-------- ������ -------- */

	class JexerExceptionBase;

	template<typename ErrorValueType>
	class JexerException;

	////////////////////////////

	// ��װBoost���쳣�׳��꣬ʹ�øú���Եõ��쳣���������ļ��������Լ�����
#define JEXER_THROW_EXCEPTION(e) BOOST_THROW_EXCEPTION(e)

	// �쳣��Ļ��࣬����������³���Ϣ�Ĵ��麯����ʹ�ø�����catch�����н����쳣��Ϣ�����
	class JexerExceptionBase : virtual public boost::exception, virtual public std::exception
	{
	public:

		// ��ӡ�쳣��Ϣ
		virtual void PrintErrorInfo() const = 0;

	};

	template<typename ErrorValueType>
	class JexerException : virtual public JexerExceptionBase
	{
	private:

		// �����쳣��Ϣ��Tag_JexerErrorInfo����Ϊ��ǩ��
		// �������쳣��Ϣ������int(�������)��string(���ļ���)��
		typedef boost::error_info<struct Tag_JexerErrorInfo, ErrorValueType> JexerErrorInfo;

	public:

		// ��Ӵ�����Ϣ
		JexerException & AddErrorInfo(const ErrorValueType & errorInfo)
		{
			*this << JexerErrorInfo(errorInfo);
			return *this;
		}

		void PrintErrorInfo() const
		{
			std::cerr << "-------- Exception --------" << std::endl;
			std::cerr << boost::diagnostic_information(*this);
			std::cerr << "---------------------------" << std::endl;
		} 

		// ��ȡ������Ϣ
		const ErrorValueType & GetErrorInfo() const
		{
			return boost::get_error_info<ErrorValueType>(*this);
		}

	};


} // namespace Jexer

#endif // JEXER_EXCEPTION_H
