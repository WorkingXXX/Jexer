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
	/*-------- 类声明 -------- */

	class JexerExceptionBase;

	template<typename ErrorValueType>
	class JexerException;

	////////////////////////////

	// 封装Boost的异常抛出宏，使用该宏可以得到异常发生所在文件、行数以及函数
#define JEXER_THROW_EXCEPTION(e) BOOST_THROW_EXCEPTION(e)

	// 异常类的基类，定义了输出新出信息的纯虚函数，使用该类在catch区块中进行异常信息的输出
	class JexerExceptionBase : virtual public boost::exception, virtual public std::exception
	{
	public:

		// 打印异常信息
		virtual void PrintErrorInfo() const = 0;

	};

	template<typename ErrorValueType>
	class JexerException : virtual public JexerExceptionBase
	{
	private:

		// 储存异常信息，Tag_JexerErrorInfo仅仅为标签，
		// 常见的异常信息类型有int(如错误码)和string(如文件名)等
		typedef boost::error_info<struct Tag_JexerErrorInfo, ErrorValueType> JexerErrorInfo;

	public:

		// 添加错误信息
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

		// 获取错误信息
		const ErrorValueType & GetErrorInfo() const
		{
			return boost::get_error_info<ErrorValueType>(*this);
		}

	};


} // namespace Jexer

#endif // JEXER_EXCEPTION_H
