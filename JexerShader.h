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
		用于获取Shader并加以标定类型
	*/
	class JexerShader : JexerResource
	{
	public:

		// 每个JexerShader必须指定其Shader类型
		// JexerShader含有一个完整的Shader源码，这个Shader的源码来自一个字符串即shaderSrc
		// shaderSrc可以就是Shader的源码，也可能是Shader的文件路径或网络URL等，
		// 这个shaderSrc的类型又shaderSrcType指定
		explicit JexerShader(JexerShaderType shaderType,
					         const STLStr& shaderSrc = "", 
						     JexerShaderSourceType shaderSrcType = JEXER_SHADER_SRC_FILEPATH);

		~JexerShader() = default;

		JexerShader(const JexerShader&) = default;

		JexerShader& operator=(const JexerShader&) = default;

		// 获取Shader源码
		STLStr GetShaderCode() const
		{
			return m_shaderCode;
		}

		// 获取Shader类型
		JexerShaderType GetShaderType() const
		{
			return m_shaderType;
		}

		// 获取Shader来源
		STLStr GetShaderSrc() const
		{
			return m_shaderSrc;
		}

		// 获取Shader来源类型
		JexerShaderSourceType GetShaderSrcType() const
		{
			return m_shaderSrcType;
		}

		// 重置Shader的来源和类型
		void ResetShaderSrcAndType(const STLStr& shaderSrc, JexerShaderSourceType shaderSrcType)
		{
			m_shaderSrc = shaderSrc;
			m_shaderSrcType = shaderSrcType;
			m_shaderCode = ParseShaderSrc();
		}

		// 判断Shader是否为空，通常只有不为空才可以用
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
		
		// 解析Shader来源以获取Shader源码
		STLStr ParseShaderSrc();

	private:
		STLStr m_shaderCode;
		JexerShaderType m_shaderType;
		STLStr m_shaderSrc;
		JexerShaderSourceType m_shaderSrcType;
	};


} // namespace Jexer


#endif // JEXER_SHADER_H
