#pragma once
#ifndef MATHUTILITIES_HPP
#define MATHUTILITIES_HPP

#include <cmath>
#include <vector>

namespace engine 
{
	namespace math
	{
		struct math_utilities
		{
			const float PI = 3.14159265f;
			int float_to_int(float pNumber);
			int float_to_even_int(float pNumber);
			float degrees_to_radians(float pDegree);
			float radians_to_degrees(float pRadian);
			float angular_distance(float pAngleA, float pAngleB);
			float interpolate(float pStartValue, float pEndValue, float pFraction);
			bool int_power_of_two(int pNumber);

			template <class type> type get_max(type pFirstNumber, type pSecondNumber)
			{
				type result;

				if (pFirstNumber >= pSecondNumber)
				{
					result = pFirstNumber;
				}
				else
				{
					result = pSecondNumber;
				}

				return result;
			}

			template <class type> type get_max(type pFirstNumber, type pSecondNumber, type pThirdNumber)
			{
				type result, firstMax;

				firstMax = getMax(pFirstNumber, pSecondNumber);
				result = getMax(firstMax, pThirdNumber);

				return result;
			}

			template <class type> type get_max(type pFirstNumber, type pSecondNumber, type pThirdNumber, type pFourthdNumber)
			{
				type result, firstMax;

				firstMax = getMax(pFirstNumber, pSecondNumber, pThirdNumber);
				result = getMax(firstMax, pFourthdNumber);

				return result;
			}

			template <class type> type get_min(type pFirstNumber, type pSecondNumber)
			{
				type result;

				if (pFirstNumber <= pSecondNumber) {
					result = pFirstNumber;
				}
				else {
					result = pSecondNumber;
				}

				return result;
			}

			template <class type> type get_min(type pFirstNumber, type pSecondNumber, type pThirdNumber)
			{
				type result, firstMin;

				firstMin = getMin(pFirstNumber, pSecondNumber);
				result = getMin(firstMin, pThirdNumber);

				return result;
			}

			template <class type> type getMin(type pFirstNumber, type pSecondNumber, type pThirdNumber, type pFourthdNumber)
			{
				type result, firstMin;

				firstMin = getMin(pFirstNumber, pSecondNumber, pThirdNumber);
				result = getMin(firstMin, pFourthdNumber);

				return result;
			}

			float clamp(float pNumber, float pMin, float pMax);
		};
	}
}

#endif