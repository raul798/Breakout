#include "math_utilities.hpp"

namespace engine 
{
	namespace math
	{
		int math_utilities::float_to_int(float pNumber)
		{
			int result;

			if (pNumber >= 0)
			{
				result = static_cast<int>(pNumber + 0.5);
			}
			else
			{
				result = static_cast<int>(pNumber - 0.5);
			}

			return result;
		}

		int math_utilities::float_to_even_int(float pNumber)
		{
			int result, firstDecimal, intNumber;

			firstDecimal = static_cast<int>(pNumber * 10) % 10;

			if (pNumber >= 0)
			{
				intNumber = static_cast<int>(pNumber + 0.5);
			}
			else
			{
				intNumber = static_cast<int>(pNumber - 0.5);
			}

			if (firstDecimal >= 5)
			{
				result = intNumber + 1;
			}
			else if (firstDecimal < 5)
			{
				result = intNumber;
			}

			return result;
		}

		float math_utilities::degrees_to_radians(float pDegree)
		{
			float result;

			result = ((pDegree * PI) / 180);

			return result;
		}

		float math_utilities::radians_to_degrees(float pRadian)
		{
			float result;

			result = ((pRadian * 180) / PI);

			return result;
		}

		float math_utilities::angular_distance(float pAngleA, float pAngleB)
		{
			float result;

			if (pAngleA < 0 && pAngleB > 0)
			{
				result = (pAngleA + pAngleB) * -1;
			}
			else if (pAngleA < 0 && pAngleB < 0)
			{
				result = (pAngleA - pAngleB) * -1;
			}
			else if (pAngleA > 0 && pAngleB > 0)
			{
				result = pAngleA - pAngleB;
			}
			else if (pAngleA > 0 && pAngleB < 0)
			{
				result = pAngleA + pAngleB;
			}
			else if (pAngleA == 0 && pAngleB < 0)
			{
				result = pAngleA - pAngleB;
			}
			else if (pAngleA == 0 && pAngleB > 0)
			{
				result = pAngleA - pAngleB;
			}
			else if (pAngleA < 0 && pAngleB == 0)
			{
				result = pAngleA * -1;
			}
			else if (pAngleA > 0 && pAngleB == 0)
			{
				result = pAngleA;
			}

			return result;
		}

		float math_utilities::interpolate(float pStartValue, float pEndValue, float pFraction)
		{
			float result;

			result = (pFraction * (pEndValue - pStartValue)) + pStartValue;

			return result;
		}

		bool math_utilities::int_power_of_two(int pNumber)
		{
			bool result;

			if (pNumber > 0 && ((pNumber & (pNumber - 1)) == 0))
			{
				result = true;
			}
			else
			{
				result = false;
			}

			return result;
		}

		float math_utilities::clamp(float pNumber, float pMin, float pMax)
		{

			if (pNumber < pMin) {
				pNumber = pMin;
			}
			else if (pNumber > pMax) {
				pNumber = pMax;
			}

			return pNumber;
		}
	}
}