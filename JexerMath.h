//
// Author : DX, 2018/6/25
//

#pragma once

#ifndef JEXER_MATH_H
#define JEXER_MATH_H

namespace Jexer
{
	/**
		¶þÎ¬ÏòÁ¿
	*/
	template<typename DataType>
	class Vector2
	{
	private:

		Vector2() = delete;

	public:

		DataType x;
		DataType y;

		Vector2(DataType x, DataType y)
			:x(x), y(y)
		{

		}

		Vector2(const Vector2<DataType>&) = default;

		Vector2& operator=(const Vector2<DataType>&) = default;

		Vector2& operator=(DataType other[2])
		{
			this.x = other[0];
			this.y = other[1];
		}

		~Vector2() = default;

	};

}


#endif
