
#include "JexerShaderSlot.h"

namespace Jexer
{
	JexerShaderSlot::JexerShaderSlot()
	{
		for (uint i = 0; i < JEXER_SHADER_NUM; i++)
		{
			JexerShaderType shaderType = static_cast<JexerShaderType>(i);
			JexerShader shaderTmp(shaderType);
			
			InsertShader(shaderTmp);
		}
	}
	
	void JexerShaderSlot::InsertShader(const JexerShader& shader)
	{
		if (m_shaderVtr.size() <= JEXER_SHADER_NUM)
		{
			m_shaderVtr[static_cast<uint>(shader.GetShaderType())] = shader;
		}
	}

	bool JexerShaderSlot::IsSlotFull() const
	{
		bool isFull = true;

		for (JexerShader shader : m_shaderVtr)
		{
			if (shader.IsShaderEmpty())
			{
				isFull = false;
				break;
			}
		}

		return isFull;
	}

	bool JexerShaderSlot::IsSlotAvailable() const
	{
		bool isAvailable = false;

		JexerShader vertexShader = GetShaderByType(JEXER_VERTEX_SHADER);
		JexerShader pixelShader  = GetShaderByType(JEXER_PIXEL_SHADER);

		if (!(vertexShader.IsShaderEmpty() || pixelShader.IsShaderEmpty()))
		{
			isAvailable = true;
		}

		return isAvailable;
	}

	JexerShader JexerShaderSlot::GetShaderByType(JexerShaderType shaderType) const
	{
		uint i = static_cast<uint>(shaderType);
		return m_shaderVtr[i];
	}

	JexerShader JexerShaderSlot::GetShaderByIndex(uint i) const
	{
		return m_shaderVtr[i];
	}

	int JexerShaderSlot::MapShaderTypeToGL(JexerShaderType shaderType)
	{
		switch (shaderType)
		{
		case JEXER_VERTEX_SHADER: return GL_VERTEX_SHADER;
		case JEXER_PIXEL_SHADER:  return GL_FRAGMENT_SHADER;
		default:
			return GL_VERTEX_SHADER;
		}
	}

} // namespace Jexer