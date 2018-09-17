//
// Author : DX, 2018/9/17
//

#pragma once

#ifndef JEXER_SHADER_PROGRAM_CREATOR_H
#define JEXER_SHADER_PROGRAM_CREATOR_H

#include "JexerPrerequisites.h"

namespace Jexer
{
	/**
		
	*/
	class JexerShaderProgramCreator
	{
	public:

		JexerShaderProgramCreator();

		~JexerShaderProgramCreator();

		// 创建Shader程序
		void CreateShaderProgram();

	protected:

		// 获取Shader
		void GetShader();

		// 编译Shader
		void CompilerShader();

		// 链接Shader
		void LinkShader();

	private:

	};


} // Jexer

#endif // JEXER_SHADER_PROGRAM_CREATOR_H
