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
		�쳣�����࣬���ڲ����쳣����������Ϣ
	*/
	class JexerException : public std::exception
	{

	};

} // namespace Jexer

#endif // JEXER_EXCEPTION_H
