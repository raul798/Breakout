#pragma once
#ifndef MATRIX_4_HPP
#define MATRIX_4_HPP

#include <iostream>

#include "vector_4.hpp"

namespace engine
{
	namespace math
	{
		class matrix_4
		{
		public:
			//constructors
			matrix_4();
			matrix_4(float pArray[16]);
			matrix_4(float pFristValue, float pSecondValue, float pThirdValue, float pFourthValue,
				float pFifthValue, float pSixthValue, float pSeventhValue, float pEighthValue,
				float pNinthValue, float pTenthValue, float pEleventhValue, float pTwelfthValue,
				float pThirteenthValue, float pFourteenthValue, float pFifteenthValue, float pSixteenthValue);

			//functions
			float *get_matrix();
			float *get_matrix_pointer();
			float *get_matrix_row(int pRowIndex);
			float *get_matrix_column(int pColumnIndex);
			void assign_matrix(float pMatrix[]);
			void set_identity();
			matrix_4 get_transpose();
			float& matrix_4::operator[](const int pRightSide);
			float get_matrix_value(int pRowIndex, int pColumnIndex);
			vector_3 get_angle();
			friend std::ostream& operator<< (std::ostream& pOstream, matrix_4 pMatrix);
			void translate_vector(vector_4 pVector);
			void rotate_from_degrees(float pDegrees);
			void rotate_from_radians(float pRadians);
			void rotate_x(float pRadians);
			void rotate_y(float pRadians);
			void rotate_z(float pRadians);
			void rotate_quaternions(float pAngle, int pRotationAxes);
			void make_ortho(const float &pMinimumXAxis, const float &pMaximumXAxis, const float &pMinimumYAxis,
				const float &pMaximumYAxis, const float &pMinimumZAxis, const float &pMaximumZAxis);
			void make_perspective(const float &pFieldOfView, const float &pNearClippingPlane, const float &pFarClippingPlane, 
				const float &pScreenAspect);
			void make_look_at(vector_3 pLookingPosition, vector_3 pTargetPosition);
			matrix_4 invert();
			void transform(matrix_4 pTranslation, matrix_4 pRotation, matrix_4 pScale);

			//arithmetic functions
			matrix_4  operator+(matrix_4 pRightSide);
			matrix_4& operator+=(matrix_4 pRightSide);
			matrix_4  operator-(matrix_4 pRightSide);
			matrix_4& operator-=(matrix_4 pRightSide);
			matrix_4  operator*(matrix_4& pRightSide);
			matrix_4  operator/(matrix_4 pRightSide);
			matrix_4& operator=(const matrix_4 pRightSide);
			friend vector_4 operator*(matrix_4 pLeftSide, vector_4 pRightSide);

		private:
			float mMatrix[16];
		};
	}
}

#endif