#include "vector_3.hpp"

namespace engine 
{
	//constructors
	vector_3::vector_3()
	{
		mX = 0.0f;
		mY = 0.0f;
		mZ = 0.0f;
		mLength = 0.0f;
	}

	vector_3::vector_3(float pX, float pY, float pZ) 
	{
		mX = pX;
		mY = pY;
		mZ = pZ;
		mLength = length();
	}

	vector_3::vector_3(float pAxes) 
	{
		mX = pAxes;
		mY = pAxes;
		mZ = pAxes;
		mLength = length();
	}

	vector_3::vector_3(const vector_2& pVector) 
	{
		mX = pVector.mX;
		mY = pVector.mY;
		mZ = 0.0f;
		mLength = length();
	}

	//functions
	float vector_3::length() const 
	{
		float result;

		result = sqrt(mX * mX + mY * mY + mZ * mZ);

		return result;
	}

	float vector_3::squared_length() const 
	{
		float result;

		result = mX * mX + mY * mY + mZ * mZ;

		return result;
	}

	float vector_3::normalize()
	{
		float inverse;

		length();

		inverse = 1.0f / mLength;
		mX *= inverse;
		mY *= inverse;
		mZ *= inverse;

		return mLength;
	}

	//operators
	vector_3& vector_3::operator=(const vector_3& pRightSide)
	{

		mX = pRightSide.mX;
		mY = pRightSide.mY;
		mZ = pRightSide.mZ;

		return *this;
	}

	vector_3 vector_3::operator+(const vector_3& pRightSide) 
	{
		float xAxis, yAxis, zAxis;

		xAxis = mX + pRightSide.mX;
		yAxis = mY + pRightSide.mY;
		zAxis = mZ + pRightSide.mZ;

		return vector_3(xAxis, yAxis, zAxis);
	}

	vector_3& vector_3::operator+=(const vector_3& pRightSide) 
	{
		mX += pRightSide.mX;
		mY += pRightSide.mY;
		mZ += pRightSide.mZ;

		return *this;
	}

	vector_3 vector_3::operator-(const vector_3& pRightSide) 
	{
		float xAxis, yAxis, zAxis;

		xAxis = mX - pRightSide.mX;
		yAxis = mY - pRightSide.mY;
		zAxis = mZ - pRightSide.mZ;

		return vector_3(xAxis, yAxis, zAxis);
	}

	vector_3& vector_3::operator-=(const vector_3& pRightSide) 
	{
		mX -= pRightSide.mX;
		mY -= pRightSide.mY;
		mZ -= pRightSide.mZ;

		return *this;
	}

	vector_3 vector_3::operator*(const vector_3& pRightSide)
	{
		float xAxis, yAxis, zAxis;

		xAxis = mX * pRightSide.mX;
		yAxis = mY * pRightSide.mY;
		zAxis = mZ * pRightSide.mZ;

		return vector_3(xAxis, yAxis, zAxis);
	}

	vector_3& vector_3::operator*=(const vector_3& pRightSide) 
	{
		mX *= pRightSide.mX;
		mY *= pRightSide.mY;
		mZ *= pRightSide.mZ;

		return *this;
	}

	vector_3 vector_3::operator/(const vector_3& pRightSide) 
	{
		float xAxis, yAxis, zAxis;

		if (pRightSide.mX == 0) 
		{
			throw "Division by zero is not defined";
		}

		if (pRightSide.mY == 0) 
		{
			throw "Division by zero is not defined";
		}

		if (pRightSide.mZ == 0) 
		{
			throw "Division by zero is not defined";
		}

		xAxis = mX / pRightSide.mX;
		yAxis = mY / pRightSide.mY;
		zAxis = mZ / pRightSide.mZ;

		return vector_3(xAxis, yAxis, zAxis);
	}

	vector_3& vector_3::operator/=(const vector_3& pRightSide) {

		float xAxis, yAxis, zAxis;

		if (pRightSide.mX == 0) 
		{
			throw "Division by zero is not defined";
		}

		if (pRightSide.mY == 0) 
		{
			throw "Division by zero is not defined";
		}

		if (pRightSide.mZ == 0) 
		{
			throw "Division by zero is not defined";
		}

		mX /= pRightSide.mX;
		mY /= pRightSide.mY;
		mZ /= pRightSide.mZ;

		return *this;
	}

	bool vector_3::operator==(const vector_3& pRightSide) 
	{
		bool result;

		if (mX == pRightSide.mX && mY == pRightSide.mY && mZ == pRightSide.mZ)
		{
			result = true;
		}
		else 
		{
			result = false;
		}

		return result;
	}

	bool vector_3::operator!=(const vector_3& pRightSide) {
		bool result;

		if (mX != pRightSide.mX && mY != pRightSide.mY && mZ != pRightSide.mZ) 
		{
			result = true;
		}
		else 
		{
			result = false;
		}

		return result;
	}

	//friend
	vector_3 operator*(float pUnit, const vector_3& pRightSide)
	{
		float xAxis, yAxis, zAxis;

		xAxis = pUnit * pRightSide.mX;
		yAxis = pUnit * pRightSide.mY;
		zAxis = pUnit * pRightSide.mZ;

		return vector_3(xAxis, yAxis, zAxis);
	}

	vector_3 operator*(const vector_3& pLeftSide, float pUnit) 
	{
		float xAxis, yAxis, zAxis;

		xAxis = pUnit * pLeftSide.mX;
		yAxis = pUnit * pLeftSide.mY;
		zAxis = pUnit * pLeftSide.mZ;

		return vector_3(xAxis, yAxis, zAxis);
	}
}