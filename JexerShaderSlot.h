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
		���Shader������������oShaderProgramCreator����ShaderProgram��
	*/
	class JexerShaderSlot
	{
	public:

		JexerShaderSlot();

		~JexerShaderSlot() = default;

		// ����Shader���Ͳ��뵽Slot��
		void InsertShader(const JexerShader& shader);

		// Slot�Ƿ��Ѿ�����Shader������ÿ��Shader��Ϊ��
		bool IsSlotFull() const;

		// Slot�Ƿ��Ѿ����ã���Slot��������Vertex Shader��Pixel Shader
		// ��������Shader��Ϊ��
		bool IsSlotAvailable() const;

		// ����Shader����������ȡShader
		JexerShader GetShaderByType(JexerShaderType shaderType) const
		{
			uint i = static_cast<uint>(shaderType);
			return m_shaderVtr[i];
		}

		// ������������ȡShader
		JexerShader GetShaderByIndex(uint i) const
		{
			return m_shaderVtr[i];
		}

		// ��ȡShader����
		STLVector<JexerShader> GetShaders() const
		{
			return m_shaderVtr;
		}

		// ��Shader����ӳ���ΪOpenGL Shader������
		static int MapShaderTypeToGL(JexerShaderType shaderType);

	protected:
	
	
	private:
		STLVector<JexerShader> m_shaderVtr;
	};


} // namespace Jexer


#endif // JEXER_SHADER_SLOT_H
