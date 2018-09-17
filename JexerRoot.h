//
// Author : DX, 2018/9/10
//

#pragma once

#ifndef JEXER_ROOT_H
#define JEXER_ROOT_H

#include "JexerSingleton.h"
#include "JexerShaderManager.h"

#include <memory>

namespace Jexer
{
	/**
		整个应用程序从这个类开始运行
	*/
	class JexerRoot : JexerSingleton<JexerRoot>
	{
	private:

		std::unique_ptr<JexerShaderManager> m_shaderMgr;
	
	public:
		
		JexerRoot() :
			m_shaderMgr(new JexerShaderManager())
		{

		}



	};

}; // Jexer

#endif // JEXER_ROOT_H