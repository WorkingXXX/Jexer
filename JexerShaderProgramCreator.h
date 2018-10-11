//
// Author : DX, 2018/9/17
//

#pragma once

#ifndef JEXER_SHADER_PROGRAM_CREATOR_H
#define JEXER_SHADER_PROGRAM_CREATOR_H

#include "JexerPrerequisites.h"
#include "JexerShaderSlot.h"

#include <GL\glew.h>

namespace Jexer
{
	/**
		����Shader������Shader Program
	*/
	class JexerShaderProgramCreator
	{
	public:

		explicit JexerShaderProgramCreator(const JexerShaderSlot& shaderSlot);

		JexerShaderProgramCreator(const JexerShaderProgramCreator&) = default;

		JexerShaderProgramCreator& operator=(const JexerShaderProgramCreator&) = default;

		~JexerShaderProgramCreator() = default;

		// ����Shader���򣬷�����ID
		ShaderProgramId CreateShaderProgram();

		// ʹ�õ�ǰ����������Shader����
		void UseCurrentShaderProgram();

	protected:

		// ����Shader
		void CompilerShader();

		// ����Shader
		void LinkShader();

	private:
		GLuint m_currShaderPrgm;
		JexerShaderSlot m_shaderSlot;
		STLVector<ShaderObjectId> m_shaderObj;
	};


} // Jexer

#endif // JEXER_SHADER_PROGRAM_CREATOR_H
