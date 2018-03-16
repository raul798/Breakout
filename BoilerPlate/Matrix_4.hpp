#pragma once
#ifndef MATRIX_4_HPP
#define MATRIX_4_HPP

#include <iostream>

#include "vector_4.hpp"

namespace engine
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
		float **get_matrix();
		float *get_matrix_row(int pRowIndex);
		float *get_matrix_column(int pColumnIndex);
		void identity();
		matrix_4 get_transpose();
		float& matrix_4::operator[](const int pRightSide);
		float get_matrix_value(int pRowIndex, int pColumnIndex);
		vector_3 get_angle();
		friend std::ostream& operator<< (std::ostream& pOstream, matrix_4 pMatrix);
		vector_4& translate_vector(vector_4 pVector);
		matrix_4 translate_matrix(vector_4 pVector);
		matrix_4 rotate_from_degrees(float pDegrees);
		matrix_4 rotate_from_radians(float pRadians);
		matrix_4 rotate_x(float pRadians);
		matrix_4 rotate_y(float pRadians);
		matrix_4 rotate_z(float pRadians);
		matrix_4 invert();
		matrix_4 transform(int pIndexValue, float pDesiredValue);
	
		//arithmetic functions
		matrix_4  operator+(matrix_4 pRightSide);
		matrix_4& operator+=(matrix_4 pRightSide);
		matrix_4  operator-(matrix_4 pRightSide);
		matrix_4& operator-=(matrix_4 pRightSide);
		matrix_4  operator*(matrix_4& pRightSide);
		matrix_4  operator/(matrix_4 pRightSide);
		matrix_4& operator=(const matrix_4 pRightSide);
	private:
		float mMatrix[16];
	};
}

#endif