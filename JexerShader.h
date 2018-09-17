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
		���ڻ�ȡShader�����Ա궨����
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
