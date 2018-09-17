//
// Author : DX, 2018/9/17
//

#pragma once

#ifndef JEXER_SHADER_H
#define JEXER_SHADER_H

#include "JexerPrerequisites.h"

#include <fstream>

#include <GL\glew.h>

namespace Jexer
{
	/**
		���ڻ�ȡShader�����Ա궨����
	*/
	class JexerShader : JexerResource
	{
	public:

		// ÿ��JexerShader����ָ����Shader����
		// JexerShader����һ��������ShaderԴ�룬���Shader��Դ������һ���ַ�����shaderSrc
		// shaderSrc���Ծ���Shader��Դ�룬Ҳ������Shader���ļ�·��������URL�ȣ�
		// ���shaderSrc��������shaderSrcTypeָ��
		explicit JexerShader(JexerShaderType shaderType,
					         const STLStr& shaderSrc = "", 
						     JexerShaderSourceType shaderSrcType = JEXER_SHADER_SRC_FILEPATH);

		~JexerShader() = default;

		JexerShader(const JexerShader&) = default;

		JexerShader& operator=(const JexerShader&) = default;

		// ��ȡShaderԴ��
		STLStr GetShaderCode() const
		{
			return m_shaderCode;
		}

		// ��ȡShader����
		JexerShaderType GetShaderType() const
		{
			return m_shaderType;
		}

		// ��ȡShader��Դ
		STLStr GetShaderSrc() const
		{
			return m_shaderSrc;
		}

		// ��ȡShader��Դ����
		JexerShaderSourceType GetShaderSrcType() const
		{
			return m_shaderSrcType;
		}

		// ����Shader����Դ������
		void ResetShaderSrcAndType(const STLStr& shaderSrc, JexerShaderSourceType shaderSrcType)
		{
			m_shaderSrc = shaderSrc;
			m_shaderSrcType = shaderSrcType;
			m_shaderCode = ParseShaderSrc();
		}

		// �ж�Shader�Ƿ�Ϊ�գ�ͨ��ֻ�в�Ϊ�ղſ�����
		bool IsShaderEmpty() const
		{
			return m_shaderCode == "";
		}

		size_t GetShaderSize() const
		{
			return m_shaderCode.length();
		}

	protected:

		JexerShader() = delete;
		
		// ����Shader��Դ�Ի�ȡShaderԴ��
		STLStr ParseShaderSrc();

	private:
		STLStr m_shaderCode;
		JexerShaderType m_shaderType;
		STLStr m_shaderSrc;
		JexerShaderSourceType m_shaderSrcType;
	};


} // namespace Jexer


#endif // JEXER_SHADER_H
