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
		根据Shader来创建Shader Program
	*/
	class JexerShaderProgramCreator
	{
	public:

		explicit JexerShaderProgramCreator(const JexerShaderSlot& shaderSlot);

		JexerShaderProgramCreator(const JexerShaderProgramCreator&) = default;

		JexerShaderProgramCreator& operator=(const JexerShaderProgramCreator&) = default;

		~JexerShaderProgramCreator() = default;

		// 创建Shader程序，返回其ID
		ShaderProgramId CreateShaderProgram();

		// 使用当前创建出来的Shader程序
		void UseCurrentShaderProgram();

	protected:

		// 编译Shader
		void CompilerShader();

		// 链接Shader
		void LinkShader();

	private:
		GLuint m_currShaderPrgm;
		JexerShaderSlot m_shaderSlot;
		STLVector<ShaderObjectId> m_shaderObj;
	};


} // Jexer

#endif // JEXER_SHADER_PROGRAM_CREATOR_H
