//
// Author : DX, 2018/6/25
//

#pragma once

#ifndef JEXER_PREREQUISTIES_H
#define JEXER_PREREQUISTIES_H

#include "JexerMath.h"
#include "JexerResource.h"

#include <string>
#include <vector>
#include <memory>

namespace Jexer
{
	/**
		��Ҫ�������ּ򻯵����ͱ�ƺͳ�����
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

	typedef std::string STLStr;
	
	template<typename T>
	using STLVector = std::vector<T>;

	template<typename T>
	using STLUPtr = std::unique_ptr<T>;

	template<typename T>
	using STLSPtr = std::shared_ptr<T>;

	template<typename T>
	using STLWPtr = std::weak_ptr<T>;

	// Shader����
	enum ShaderType
	{
		JEXER_GL_VERTEX_SHADER,
		JEXER_GL_PIXEL_SHADER,
		JEXER_SHADER_NUM
	};

	// Shader��Դ������
	enum ShaderSourceType
	{
		JEXER_SHADER_SRC_CODESTR,
		JEXER_SHADER_SRC_FILEPATH,
		JEXER_SHADER_SRC_URL,
		JEXER_SHADER_SRC_NUM
	};

}

#endif
