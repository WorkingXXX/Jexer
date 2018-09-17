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
		用于获取Shader并加以标定类型
	*/
	class JexerShader : JexerResource
	{
	public:

		JexerShader();

		// JexerShader可以从一个字符串创建
		// 这个字符串shaderSrc可以是Shader源码、Shader的文件路径或者是Shader的URL等
		// 默认情况下这个这个shaderSrc的类型为JEXER_SHADER_SRC_FILE_PATH, 也即Shader的文件路径
		explicit JexerShader(const STLStr& shaderSrc, ShaderSourceType shaderSrcType = JEXER_SHADER_SRC_FILEPATH);

		~JexerShader() = default;

		JexerShader(const JexerShader&) = default;

		JexerShader& operator=(const JexerShader&) = default;

		// 获取Shader源码
		STLStr GetShaderCode() const
		{
			return m_shaderCode;
		}

		// 获取Shader来源
		STLStr GetShaderSrc() const
		{
			return m_shaderSrc;
		}

		// 获取Shader来源类型
		ShaderSourceType GetShaderSrcType() const
		{
			return m_shaderSrcType;
		}

		// 重置Shader的来源和类型
		void ResetShaderSrcAndType(const STLStr& shaderSrc, ShaderSourceType shaderSrcType)
		{
			m_shaderSrc = shaderSrc;
			m_shaderSrcType = shaderSrcType;
			m_shaderCode = ParseShaderSrc();
		}

	protected:
		
		// 解析Shader来源以获取Shader源码
		STLStr ParseShaderSrc();

	private:
		STLStr m_shaderCode;
		STLStr m_shaderSrc;
		ShaderSourceType m_shaderSrcType;
	};


} // namespace Jexer


#endif // JEXER_SHADER_H
