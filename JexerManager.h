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
		������Դ�������ڳ�������ʱֻ����һ��ʵ��
	*/
	class JexerManager : JexerSingleton<JexerManager>
	{
	private:

		JexerManager(const JexerManager&);

	public:

		JexerManager() = default;

		~JexerManager() = default;

		// Ϊ�µ���Դ����ռ�
		virtual std::unique_ptr<JexerResource> Create() = 0;

	};
} // Jexer


#endif // JEXER_MANAGER_H