#include "vector_4.hpp"

namespace engine {

	//constructors
	vector_4::vector_4() 
	{
		mX = 0.0f;
		mY = 0.0f;
		mZ = 0.0f;
		mW = 0.0f;
		mLength = 0.0f;
	}

	vector_4::vector_4(float pX, float pY, float pZ, float pW) 
	{

		mX = pX;
		mY = pY;
		mZ = pZ;
		mW = pW;
		mLength = length();
	}

	vector_4::vector_4(float pAxesAndW) 
	{
		mX = pAxesAndW;
		mY = pAxesAndW;
		mZ = pAxesAndW;
		mW = pAxesAndW;
		mLength = length();
	}

	vector_4::vector_4(const vector_2& pVector) 
	{
		mX = pVector.mX;
		mY = pVector.mY;
		mZ = 0.0f;
		mW = 0.0f;
		mLength = length();
	}

	vector_4::vector_4(const vector_3& pVector)
	{
		mX = pVector.mX;
		mY = pVector.mY;
		mZ = pVector.mZ;
		mW = 0.0f;
		mLength = length();
	}

	//functions
	float vector_4::length() const 
	{
		float result;

		result = sqrt(mX * mX + mY * mY + mZ * mZ * mW * mW);

		return result;
	}

	float vector_4::squared_length() const
	{
		float result;

		result = mX * mX + mY * mY + mZ * mZ * mW * mW;

		return result;
	}

	float vector_4::normalize() 
	{
		float inverse;

		length();

		inverse = 1.0f / mLength;
		mX *= inverse;
		mY *= inverse;
		mZ *= inverse;
		mW *= inverse;

		return mLength;
	}

	//operators
	vector_4& vector_4::operator=(const vector_4& pRightSide)
	{

		mX = pRightSide.mX;
		mY = pRightSide.mY;
		mZ = pRightSide.mZ;
		mW = pRightSide.mW;

		return *this;
	}

	vector_4 vector_4::operator+(const vector_4& pRightSide)
	{
		float xAxis, yAxis, zAxis, wComponent;

		xAxis = mX + pRightSide.mX;
		yAxis = mY + pRightSide.mY;
		zAxis = mZ + pRightSide.mZ;
		wComponent = mW + pRightSide.mW;

		return vector_4(xAxis, yAxis, zAxis, wComponent);
	}

	vector_4& vector_4::operator+=(const vector_4& pRightSide)
	{

		mX += pRightSide.mX;
		mY += pRightSide.mY;
		mZ += pRightSide.mZ;
		mW += pRightSide.mW;

		return *this;
	}

	vector_4 vector_4::operator-(const vector_4& pRightSide)
	{
		float xAxis, yAxis, zAxis, wComponent;

		xAxis = mX - pRightSide.mX;
		yAxis = mY - pRightSide.mY;
		zAxis = mZ - pRightSide.mZ;
		wComponent = mW - pRightSide.mW;

		return vector_4(xAxis, yAxis, zAxis, wComponent);
	}

	vector_4& vector_4::operator-=(const vector_4& pRightSide)
	{
		mX -= pRightSide.mX;
		mY -= pRightSide.mY;
		mZ -= pRightSide.mZ;
		mW -= pRightSide.mW;

		return *this;
	}

	vector_4 vector_4::operator*(const vector_4& pRightSide)
	{
		float xAxis, yAxis, zAxis, wComponent;

		xAxis = mX * pRightSide.mX;
		yAxis = mY * pRightSide.mY;
		zAxis = mZ * pRightSide.mZ;
		wComponent = mW * pRightSide.mW;

		return vector_4(xAxis, yAxis, zAxis, wComponent);
	}

	vector_4& vector_4::operator*=(const vector_4& pRightSide)
	{
		mX *= pRightSide.mX;
		mY *= pRightSide.mY;
		mZ *= pRightSide.mZ;
		mW *= pRightSide.mW;

		return *this;
	}

	vector_4 vector_4::operator/(const vector_4& pRightSide)
	{
		float xAxis, yAxis, zAxis, wComponent;

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

		if (pRightSide.mW == 0) 
		{
			throw "Division by zero is not defined";
		}

		xAxis = mX / pRightSide.mX;
		yAxis = mY / pRightSide.mY;
		zAxis = mZ / pRightSide.mZ;
		wComponent = mW / pRightSide.mW;

		return vector_4(xAxis, yAxis, zAxis, wComponent);
	}

	vector_4& vector_4::operator/=(const vector_4& pRightSide)
	{
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

		if (pRightSide.mW == 0)
		{
			throw "Division by zero is not defined";
		}

		mX /= pRightSide.mX;
		mY /= pRightSide.mY;
		mZ /= pRightSide.mZ;
		mW /= pRightSide.mW;

		return *this;
	}

	bool vector_4::operator==(const vector_4& pRightSide) 
	{
		bool result;

		if (mX == pRightSide.mX && mY == pRightSide.mY && mZ == pRightSide.mZ && mW == pRightSide.mW) 
		{
			result = true;
		}
		else 
		{
			result = false;
		}

		return result;
	}

	bool vector_4::operator!=(const vector_4& pRightSide) 
	{
		bool result;

		if (mX != pRightSide.mX || mY != pRightSide.mY || mZ != pRightSide.mZ)
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
	vector_4 operator*(float pUnit, const vector_4& pRightSide) 
	{
		float xAxis, yAxis, zAxis, wComponent;

		xAxis = pUnit * pRightSide.mX;
		yAxis = pUnit * pRightSide.mY;
		zAxis = pUnit * pRightSide.mZ;
		wComponent = pUnit * pRightSide.mW;

		return vector_4(xAxis, yAxis, zAxis, wComponent);
	}

	vector_4 operator*(const vector_4& pLeftSide, float pUnit) 
	{
		float xAxis, yAxis, zAxis, wComponent;

		xAxis = pUnit * pLeftSide.mX;
		yAxis = pUnit * pLeftSide.mY;
		zAxis = pUnit * pLeftSide.mZ;
		wComponent = pUnit * pLeftSide.mW;

		return vector_4(xAxis, yAxis, zAxis, wComponent);
	}
}