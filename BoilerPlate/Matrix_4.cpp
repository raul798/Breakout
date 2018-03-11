#include "matrix_4.hpp"

namespace engine
{
	matrix_4::matrix_4()
	{
		//matrix[row][column]
		//first column
		mMatrix[0][0] = 1.0f;
		mMatrix[1][0] = 0.0f;
		mMatrix[2][0] = 0.0f;
		mMatrix[3][0] = 0.0f;

		//second column
		mMatrix[0][1] = 0.0f;
		mMatrix[1][1] = 1.0f;
		mMatrix[2][1] = 0.0f;
		mMatrix[3][1] = 0.0f;

		//third column
		mMatrix[0][2] = 0.0f;
		mMatrix[1][2] = 0.0f;
		mMatrix[2][2] = 1.0f;
		mMatrix[3][2] = 0.0f;

		//fourth column
		mMatrix[0][3] = 0.0f;
		mMatrix[1][3] = 0.0f;
		mMatrix[2][3] = 0.0f;
		mMatrix[3][3] = 1.0f;
	}
	matrix_4::matrix_4(float pArray[15])
	{
		//matrix[row][column]
		//first column
		mMatrix[0][0] = pArray[0];
		mMatrix[1][0] = pArray[1];
		mMatrix[2][0] = pArray[2];
		mMatrix[3][0] = pArray[3];

		//second column
		mMatrix[0][1] = pArray[4];
		mMatrix[1][1] = pArray[5];
		mMatrix[2][1] = pArray[6];
		mMatrix[3][1] = pArray[7];

		//third column
		mMatrix[0][2] = pArray[8];
		mMatrix[1][2] = pArray[9];
		mMatrix[2][2] = pArray[10];
		mMatrix[3][2] = pArray[11];

		//fourth column
		mMatrix[0][3] = pArray[12];
		mMatrix[1][3] = pArray[13];
		mMatrix[2][3] = pArray[14];
		mMatrix[3][3] = pArray[15];
	}
	matrix_4::matrix_4(float pValue0, float pValue1, float pValue2, float pValue3,
					   float pValue4, float pValue5, float pValue6, float pValue7,
					   float pValue8, float pValue9, float pValue10, float pValue11,
					   float pValue12, float pValue13, float pValue14, float pValue15)
	{
		//matrix[row][column]
		//first column
		mMatrix[0][0] = pValue0;
		mMatrix[1][0] = pValue1;
		mMatrix[2][0] = pValue2;
		mMatrix[3][0] = pValue3;

		//second column
		mMatrix[0][1] = pValue4;
		mMatrix[1][1] = pValue5;
		mMatrix[2][1] = pValue6;
		mMatrix[3][1] = pValue7;

		//third column
		mMatrix[0][2] = pValue8;
		mMatrix[1][2] = pValue9;
		mMatrix[2][2] = pValue10;
		mMatrix[3][2] = pValue11;

		//fourth column
		mMatrix[0][3] = pValue12;
		mMatrix[1][3] = pValue13;
		mMatrix[2][3] = pValue14;
		mMatrix[3][3] = pValue15;
	}

	matrix_4 matrix_4::operator+(matrix_4 pRightSide)
	{
		matrix_4 matrix;
		
		for (int i = 0; i < 4; i++) 
		{
			for (int j = 0; j < 4; j++)
			{
				matrix.mMatrix[i][j] = mMatrix[i][j] + pRightSide.mMatrix[i][j];
			}
		}

		return matrix;
	}

	matrix_4& matrix_4::operator+=(matrix_4 pRightSide)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[i][j] += pRightSide.mMatrix[i][j];
			}
		}
	}

	matrix_4 matrix_4::operator-(matrix_4 pRightSide)
	{
		matrix_4 matrix;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				matrix.mMatrix[i][j] = mMatrix[i][j] - pRightSide.mMatrix[i][j];
			}
		}

		return matrix;
	}

	matrix_4& matrix_4::operator-=(matrix_4 pRightSide)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[i][j] -= pRightSide.mMatrix[i][j];
			}
		}
	}

	matrix_4 matrix_4::operator*(matrix_4 pRightSide)
	{
		matrix_4 matrix;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				matrix.mMatrix[i][j] = mMatrix[i][j] * pRightSide.mMatrix[i][j];
			}
		}

		return matrix;
	}

	matrix_4& matrix_4::operator*=(matrix_4 pRightSide)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[i][j] *= pRightSide.mMatrix[i][j];
			}
		}
	}

	matrix_4 matrix_4::operator/(matrix_4 pRightSide)
	{
		matrix_4 matrix;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				matrix.mMatrix[i][j] = mMatrix[i][j] / pRightSide.mMatrix[i][j];
			}
		}

		return matrix;
	}

	matrix_4& matrix_4::operator/=(matrix_4 pRightSide)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[i][j] /= pRightSide.mMatrix[i][j];
			}
		}
	}
}
