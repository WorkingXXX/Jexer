
#include "JexerShader.h"

namespace Jexer
{
	JexerShader::JexerShader()
		:m_shaderCode(""), m_shaderSrc(""), m_shaderSrcType(JEXER_SHADER_SRC_URL)
	{

	}

	JexerShader::JexerShader(const STLStr& shaderSrc, ShaderSourceType shaderSrcType)
		:m_shaderCode(""), m_shaderSrc(shaderSrc), m_shaderSrcType(shaderSrcType)
	{
		m_shaderCode = ParseShaderSrc();
	}

	STLStr JexerShader::ParseShaderSrc()
	{
		STLStr shaderCode = "";
		std::fstream shaderFile(m_shaderSrc, std::ios::out);
		STLUPtr<char> shaderChars = 0;
		size_t shaderCharsCount = 0;

		switch (m_shaderSrcType)
		{
		case JEXER_SHADER_SRC_CODESTR:
			shaderCode = m_shaderSrc;
			break;
		default:
		case JEXER_SHADER_SRC_FILEPATH:
			if (shaderFile.is_open())
			{
				shaderCharsCount = shaderFile.tellg();
				shaderChars = STLUPtr<char>(new char[shaderCharsCount]);
				shaderFile.seekg(0, std::ios::beg);
				shaderFile.read(shaderChars.get(), shaderCharsCount);
				shaderCode = STLStr(shaderChars.get());
				shaderFile.close();
			}
			break;
		case JEXER_SHADER_SRC_URL:
			break;
		}

		return shaderCode;
	}

} // namespace Jexer