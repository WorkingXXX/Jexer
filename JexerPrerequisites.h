//
// Author : DX, 2018/6/25
//

#pragma once

#ifndef JEXER_PREREQUISTIES_H
#define JEXER_PREREQUISTIES_H

#include "JexerMath.h"
#include "JexerResource.h"

#include <string>

namespace Jexer
{
	/**
		主要包括各种简化的类型别称和常量等
	*/

	typedef unsigned char      uchar;
	typedef unsigned short     ushort;
	typedef unsigned int       uint;
	typedef unsigned long      ulong;
	typedef unsigned long long ullong;

	typedef Vector2<int>    VtrInt2;
	typedef Vector2<uint>   VtrUInt2;
	typedef Vector2<float>  VtrFlt2;
	typedef Vector2<double> VtrDlb2;

	typedef std::string Str;

	// Shader类型
	enum ShaderType
	{
		JEXER_GL_VERTEX_SHADER,
		JEXER_GL_PIXEL_SHADER,
		JEXER_SHADER_NUM
	};

}

#endif
