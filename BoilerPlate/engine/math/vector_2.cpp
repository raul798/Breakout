#include "vector_2.hpp"

namespace engine 
{
	namespace math
	{
		//constructors
		vector_2::vector_2()
		{
			mX = 0.0f;
			mY = 0.0f;
			mLength = 0.0f;
		}

		vector_2::vector_2(float pX, float pY)
		{
			mX = pX;
			mY = pY;
			mLength = length();
		}

		vector_2::vector_2(float pAxes)
		{
			mX = pAxes;
			mY = pAxes;
			mLength = length();
		}

		//functions
		float vector_2::length() const
		{
			float result;

			result = sqrt(mX * mX + mY * mY);

			return result;
		}

		float vector_2::squared_length() const
		{
			float result;

			result = mX * mX + mY * mY;

			return result;
		}

		float vector_2::normalize()
		{
			float inverse;

			length();

			inverse = 1.0f / mLength;
			mX *= inverse;
			mY *= inverse;

			return mLength;
		}

		//operators
		vector_2& vector_2::operator=(const vector_2& pRightSide)
		{
			mX = pRightSide.mX;
			mY = pRightSide.mY;

			return *this;
		}

		vector_2 vector_2::operator+(const vector_2& pRightSide)
		{
			float xAxis, yAxis;

			xAxis = mX + pRightSide.mX;
			yAxis = mY + pRightSide.mY;

			return vector_2(xAxis, yAxis);
		}

		vector_2& vector_2::operator+=(const vector_2& pRightSide)
		{

			mX += pRightSide.mX;
			mY += pRightSide.mY;

			return *this;
		}

		vector_2 vector_2::operator-(const vector_2& pRightSide)
		{
			float xAxis, yAxis;

			xAxis = mX - pRightSide.mX;
			yAxis = mY - pRightSide.mY;

			return vector_2(xAxis, yAxis);
		}

		vector_2& vector_2::operator-=(const vector_2& pRightSide)
		{
			mX -= pRightSide.mX;
			mY -= pRightSide.mY;

			return *this;
		}

		vector_2 vector_2::operator*(const vector_2& pRightSide)
		{
			float xAxis, yAxis;

			xAxis = mX * pRightSide.mX;
			yAxis = mY * pRightSide.mY;

			return vector_2(xAxis, yAxis);
		}

		vector_2& vector_2::operator*=(const vector_2& pRightSide)
		{
			mX *= pRightSide.mX;
			mY *= pRightSide.mY;

			return *this;
		}

		vector_2 vector_2::operator/(const vector_2& pRightSide)
		{
			float xAxis, yAxis;

			if (pRightSide.mX == 0)
			{
				throw "Division by zero is not defined";
			}

			if (pRightSide.mY == 0)
			{
				throw "Division by zero is not defined";
			}

			xAxis = mX / pRightSide.mX;
			yAxis = mY / pRightSide.mY;

			return vector_2(xAxis, yAxis);
		}

		vector_2& vector_2::operator/=(const vector_2& pRightSide)
		{

			if (pRightSide.mX == 0)
			{
				throw "Division by zero is not defined";
			}

			if (pRightSide.mY == 0)
			{
				throw "Division by zero is not defined";
			}

			mX /= pRightSide.mX;
			mY /= pRightSide.mY;

			return *this;
		}

		bool vector_2::operator==(const vector_2& pRightSide)
		{
			bool result;

			if (mX == pRightSide.mX && mY == pRightSide.mY)
			{
				result = true;
			}
			else
			{
				result = false;
			}

			return result;
		}

		bool vector_2::operator!=(const vector_2& pRightSide)
		{
			bool result;

			if (mX != pRightSide.mX || mY != pRightSide.mY)
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
		vector_2 operator*(float pUnit, const vector_2& pRightSide)
		{
			float xAxis, yAxis;

			xAxis = pUnit * pRightSide.mX;
			yAxis = pUnit * pRightSide.mY;

			return vector_2(xAxis, yAxis);
		}

		vector_2 operator*(const vector_2& pLeftSide, float pUnit)
		{
			float xAxis, yAxis;

			xAxis = pUnit * pLeftSide.mX;
			yAxis = pUnit * pLeftSide.mY;

			return vector_2(xAxis, yAxis);
		}
	}
}