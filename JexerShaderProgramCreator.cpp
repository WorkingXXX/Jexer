
#include "JexerShaderProgramCreator.h"

namespace Jexer
{

	JexerShaderProgramCreator::JexerShaderProgramCreator(const JexerShaderSlot& shaderSlot)
		:m_currShaderPrgm(0)
	{
		m_shaderObj.resize(JEXER_SHADER_NUM);
	}

	ShaderProgramId JexerShaderProgramCreator::CreateShaderProgram()
	{
		CompilerShader();
		LinkShader();
		return m_currShaderPrgm;
	}

	void JexerShaderProgramCreator::CompilerShader()
	{
		if (m_shaderSlot.IsSlotAvailable())
		{
			for (uint i = 0; i < JEXER_SHADER_NUM; i++)
			{
				JexerShader shader = m_shaderSlot.GetShaderByIndex(i);
			
				if (shader.IsShaderEmpty())
				{
					m_shaderObj[i] = 0;
				}
				else
				{
					const char* shaderCodeChars = shader.GetShaderCode().c_str();
					const GLint shaderCodeSize = static_cast<GLint>(shader.GetShaderSize());
					ShaderObjectId shaderId = glCreateShader(JexerShaderSlot::MapShaderTypeToGL(shader.GetShaderType()));
					glShaderSource(shaderId, 1, &shaderCodeChars, &shaderCodeSize);
					glCompileShader(shaderId);

					m_shaderObj[i] = shaderId;
				}
			}
		}
	}

	void JexerShaderProgramCreator::LinkShader()
	{
		m_currShaderPrgm = glCreateProgram();

		for (GLuint shaderId : m_shaderObj)
		{
			glAttachShader(m_currShaderPrgm, shaderId);
		}

		glLinkProgram(m_currShaderPrgm);
	}

	void JexerShaderProgramCreator::UseCurrentShaderProgram()
	{
		glUseProgram(m_currShaderPrgm);
	}

} // namespace Jexer