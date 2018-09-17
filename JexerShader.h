//
// Author : DX, 2018/9/17
//

#pragma once

#ifndef JEXER_SHADER_H
#define JEXER_SHADER_H

#include "JexerPrerequisites.h"

namespace Jexer
{
	/**
		用于获取Shader并加以标定类型
	*/
	class JexerShader : JexerResource
	{
	public:

		JexerShader(const Str& shaderSrc);

		virtual ~JexerShader() = default;

		JexerShader(const JexerShader&) = default;

		JexerShader& operator=(const JexerShader&) = default;

	protected:

	private:

		JexerShader() = delete;

	};


} // Jexer


#endif // JEXER_SHADER_H
