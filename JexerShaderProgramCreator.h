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

		// ����Shader����
		void CreateShaderProgram();

	protected:

		// ��ȡShader
		void GetShader();

		// ����Shader
		void CompilerShader();

		// ����Shader
		void LinkShader();

	private:

	};


} // Jexer

#endif // JEXER_SHADER_PROGRAM_CREATOR_H
