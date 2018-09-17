//
// Author : DX, 2018/9/17
//

#pragma once

#ifndef JEXER_SHADER_H
#define JEXER_SHADER_H

#include "JexerPrerequisites.h"

#include <fstream>

namespace Jexer
{
	/**
		���ڻ�ȡShader�����Ա궨����
	*/
	class JexerShader : JexerResource
	{
	public:

		JexerShader();

		// JexerShader���Դ�һ���ַ�������
		// ����ַ���shaderSrc������ShaderԴ�롢Shader���ļ�·��������Shader��URL��
		// Ĭ�������������shaderSrc������ΪJEXER_SHADER_SRC_FILE_PATH, Ҳ��Shader���ļ�·��
		explicit JexerShader(const STLStr& shaderSrc, ShaderSourceType shaderSrcType = JEXER_SHADER_SRC_FILEPATH);

		~JexerShader() = default;

		JexerShader(const JexerShader&) = default;

		JexerShader& operator=(const JexerShader&) = default;

		// ��ȡShaderԴ��
		STLStr GetShaderCode() const
		{
			return m_shaderCode;
		}

		// ��ȡShader��Դ
		STLStr GetShaderSrc() const
		{
			return m_shaderSrc;
		}

		// ��ȡShader��Դ����
		ShaderSourceType GetShaderSrcType() const
		{
			return m_shaderSrcType;
		}

		// ����Shader����Դ������
		void ResetShaderSrcAndType(const STLStr& shaderSrc, ShaderSourceType shaderSrcType)
		{
			m_shaderSrc = shaderSrc;
			m_shaderSrcType = shaderSrcType;
			m_shaderCode = ParseShaderSrc();
		}

	protected:
		
		// ����Shader��Դ�Ի�ȡShaderԴ��
		STLStr ParseShaderSrc();

	private:
		STLStr m_shaderCode;
		STLStr m_shaderSrc;
		ShaderSourceType m_shaderSrcType;
	};


} // namespace Jexer


#endif // JEXER_SHADER_H
