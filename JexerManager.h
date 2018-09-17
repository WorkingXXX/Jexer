//
// Author : DX, 2018/9/11
//

#pragma once

#ifndef JEXER_MANAGER_H
#define JEXER_MANAGER_H

#include "JexerSingleton.h"
#include "JexerResource.h"

#include <memory>

namespace Jexer
{
	/**
		所有资源管理类在程序运行时只能有一个实例
	*/
	class JexerManager : JexerSingleton<JexerManager>
	{
	private:

		JexerManager(const JexerManager&);

	public:

		JexerManager() = default;

		~JexerManager() = default;

		// 为新的资源申请空间
		virtual std::unique_ptr<JexerResource> Create() = 0;

	};
} // Jexer


#endif // JEXER_MANAGER_H