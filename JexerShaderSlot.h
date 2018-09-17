//
// Author : DX, 2018/9/17
//

#pragma once

#ifndef JEXER_SHADER_SLOT_H
#define JEXER_SHADER_SLOT_H

#include "JexerPrerequisites.h"
#include "JexerShader.h"

namespace Jexer
{
	/**
		存放Shader的容器，用与給ShaderProgramCreator创建ShaderProgram用
	*/
	class JexerShaderSlot
	{
	public:

		JexerShaderSlot();

		~JexerShaderSlot() = default;

		// 根据Shader类型插入到Slot中
		void InsertShader(const JexerShader& shader);

		// Slot是否已经插满Shader，并且每个Shader不为空
		bool IsSlotFull() const;

		// Slot是否已经可用，即Slot中至少有Vertex Shader和Pixel Shader
		// 且这两个Shader不为空
		bool IsSlotAvailable() const;

		// 根据Shader的类型来获取Shader
		JexerShader GetShaderByType(JexerShaderType shaderType) const;

		// 根据索引来获取Shader
		JexerShader GetShaderByIndex(uint i) const;

		// 获取Shader数组
		STLVector<JexerShader> GetShaders() const
		{
			return m_shaderVtr;
		}

		// 把Shader类型映射成为OpenGL Shader的类型
		static int MapShaderTypeToGL(JexerShaderType shaderType);

	protected:
	
	
	private:
		STLVector<JexerShader> m_shaderVtr;
	};


} // namespace Jexer


#endif // JEXER_SHADER_SLOT_H
