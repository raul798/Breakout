#pragma once
#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include "vector_3.hpp"

namespace engine 
{
	struct vector_4 
	{
		//members
		float mX;
		float mY;
		float mZ;
		float mW;
		float mLength;

		//constructors
		vector_4();
		vector_4(float pX, float pY, float pZ, float pW);
		vector_4(float pAxesAndW);
		vector_4(const vector_2& pVector);
		vector_4(const vector_3& pVector);


		//functions
		float length() const; //const
		float squared_length() const; //const
		float normalize();

		//overload operators
		vector_4& operator=(const vector_4& pRightSide);
		vector_4  operator+(const vector_4& pRightSide);
		vector_4& operator+=(const vector_4& pRightSide);
		vector_4  operator-(const vector_4& pRightSide);
		vector_4& operator-=(const vector_4& pRightSide);
		vector_4  operator*(const vector_4& pRightSide);
		vector_4& operator*=(const vector_4& pRightSide);
		vector_4  operator/(const vector_4& pRightSide);
		vector_4& operator/=(const vector_4& pRightSide);
		bool	  operator==(const vector_4& pRightSide);
		bool      operator!=(const vector_4& pRightSide);
		friend vector_4 operator*(float pUnit, const vector_4& pRightSide);
		friend vector_4 operator*(const vector_4& pLeftSide, float pUnit);
	};
}

#endif
