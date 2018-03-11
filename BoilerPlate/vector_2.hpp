#pragma once
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include "math_utilities.hpp"

namespace engine 
{
	struct vector_2 
	{
		//members
		float mX;
		float mY;
		float mLength;

		//constructors
		vector_2();
		vector_2(float pX, float pY);
		vector_2(float pAxes);

		//functions
		float length() const;
		float squared_length() const;
		float normalize();

		//overload operators
		vector_2& operator=(const vector_2& pRightSide);
		vector_2 operator+(const vector_2& pRightSide);
		vector_2& operator+=(const vector_2& pRightSide);
		vector_2  operator-(const vector_2& pRightSide);
		vector_2& operator-=(const vector_2& pRightSide);
		vector_2  operator*(const vector_2& pRightSide);
		vector_2& operator*=(const vector_2& pRightSide);
		vector_2  operator/(const vector_2& pRightSide);
		vector_2& operator/=(const vector_2& pRightSide);
		bool	 operator==(const vector_2& pRightSide);
		bool     operator!=(const vector_2& pRightSide);
		friend vector_2 operator*(float pUnit, const vector_2& pRightSide);
		friend vector_2 operator*(const vector_2& pLeftSide, float pUnit);
	};
}

#endif