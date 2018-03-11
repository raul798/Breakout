#pragma once
#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include "vector_2.hpp"

namespace engine 
{
	struct vector_3 
	{
		//members
		float mX;
		float mY;
		float mZ;
		float mLength;

		//constructors
		vector_3();
		vector_3(float pX, float pY, float pZ);
		vector_3(float pAxes);
		vector_3(const vector_2& pVector);


		//functions
		float length() const; //const
		float squared_length() const; //const
		float normalize();

		//overload operators
		vector_3& operator=(const vector_3& pRightSide);
		vector_3  operator+(const vector_3& pRightSide);
		vector_3& operator+=(const vector_3& pRightSide);
		vector_3  operator-(const vector_3& pRightSide);
		vector_3& operator-=(const vector_3& pRightSide);
		vector_3  operator*(const vector_3& pRightSide);
		vector_3& operator*=(const vector_3& pRightSide);
		vector_3  operator/(const vector_3& pRightSide);
		vector_3& operator/=(const vector_3& pRightSide);
		bool	  operator==(const vector_3& pRightSide);
		bool      operator!=(const vector_3& pRightSide);
		friend vector_3 operator*(float pUnit, const vector_3& pRightSide);
		friend vector_3 operator*(const vector_3& pLeftSide, float pUnit);
	};
}

#endif