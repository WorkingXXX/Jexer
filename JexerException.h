//
// Author : DX, 2018/9/18
//

#pragma once

#ifndef JEXER_EXCEPTION_H
#define JEXER_EXCEPTION_H

#include <exception>

namespace Jexer
{
	/**
		异常处理类，用于捕获异常并输出相关信息
	*/
	class JexerException : public std::exception
	{

	};

} // namespace Jexer

#endif // JEXER_EXCEPTION_H
