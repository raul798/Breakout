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

	matrix_4::matrix_4(float pArray[16])
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

	matrix_4::matrix_4(float pFristValue, float pSecondValue, float pThirdValue, float pFourthValue,
					   float pFifthValue, float pSixthValue, float pSeventhValue, float pEighthValue,
					   float pNinthValue, float pTenthValue, float pEleventhValue, float pTwelfthValue,
					   float pThirteenthValue, float pFourteenthValue, float pFifteenthValue, float pSixteenthValue)
	{
		//matrix[row][column]
		//first column
		mMatrix[0][0] = pFristValue;
		mMatrix[1][0] = pSecondValue;
		mMatrix[2][0] = pThirdValue;
		mMatrix[3][0] = pFourthValue;

		//second column
		mMatrix[0][1] = pFifthValue;
		mMatrix[1][1] = pSixthValue;
		mMatrix[2][1] = pSeventhValue;
		mMatrix[3][1] = pEighthValue;

		//third column
		mMatrix[0][2] = pNinthValue;
		mMatrix[1][2] = pTenthValue;
		mMatrix[2][2] = pEleventhValue;
		mMatrix[3][2] = pTwelfthValue;

		//fourth column
		mMatrix[0][3] = pThirteenthValue;
		mMatrix[1][3] = pFourteenthValue;
		mMatrix[2][3] = pFifteenthValue;
		mMatrix[3][3] = pSixteenthValue;
	}

	float **matrix_4::get_matrix()
	{
		float** matrix = new float*[4];

		for (int i = 0; i < 4; i++)
		{
			matrix[i] = new float[4];

			for (int j = 0; j < 4; j++)
			{
				matrix[i][j] = mMatrix[i][j];
			}
		}

		return matrix;
	}

	float *matrix_4::get_matrix_row(int pRowIndex)
	{
		float matrixRow[3];

		for (int i = 0; i < 4; i++)
		{
			matrixRow[i] = mMatrix[pRowIndex][i];
		}

		return matrixRow;
	}

	float *matrix_4::get_matrix_column(int pColumnIndex)
	{
		float matrixColumn[3];

		for (int i = 0; i < 4; i++)
		{
			matrixColumn[i] = mMatrix[i][pColumnIndex];
		}

		return matrixColumn;
	}

	void matrix_4::identity()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i == j)
				{
					mMatrix[i][j] = 1;
				}
				else
				{
					mMatrix[i][j] = 0;
				}
			}
		}
	}

	matrix_4 matrix_4::get_transpose()
	{
		matrix_4 transposeMatrix;

		//first column
		transposeMatrix.mMatrix[0][0] = mMatrix[0][0];
		transposeMatrix.mMatrix[0][1] = mMatrix[1][0];
		transposeMatrix.mMatrix[0][2] = mMatrix[2][0];
		transposeMatrix.mMatrix[0][3] = mMatrix[3][0];

		//second column
		transposeMatrix.mMatrix[0][1] = mMatrix[0][1];
		transposeMatrix.mMatrix[1][1] = mMatrix[1][1];
		transposeMatrix.mMatrix[1][2] = mMatrix[2][1];
		transposeMatrix.mMatrix[3][1] = mMatrix[3][1];

		//third column
		transposeMatrix.mMatrix[0][2] = mMatrix[0][2];
		transposeMatrix.mMatrix[2][1] = mMatrix[1][2];
		transposeMatrix.mMatrix[2][2] = mMatrix[2][2];
		transposeMatrix.mMatrix[2][3] = mMatrix[3][2];

		//fourth column
		transposeMatrix.mMatrix[0][3] = mMatrix[0][3];
		transposeMatrix.mMatrix[3][1] = mMatrix[1][3];
		transposeMatrix.mMatrix[3][2] = mMatrix[2][3];
		transposeMatrix.mMatrix[3][3] = mMatrix[3][3];

		return transposeMatrix;
	}

	float matrix_4::get_matrix_value(int pRowIndex, int pColumnIndex)
	{
		return mMatrix[pRowIndex][pColumnIndex];
	}

	matrix_4 matrix_4::invert()
	{
		float determinant;
		matrix_4 *inverse, *duplicateMatrix;
		duplicateMatrix = this;

		inverse->mMatrix[0][0] = duplicateMatrix->mMatrix[1][1]	* duplicateMatrix->mMatrix[2][2] * duplicateMatrix->mMatrix[3][3] -
								 duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[3][2] * duplicateMatrix->mMatrix[2][3] -
								 duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[3][3] +
								 duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[3][1] * duplicateMatrix->mMatrix[2][3] +
								 duplicateMatrix->mMatrix[1][3] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[3][2] -
								 duplicateMatrix->mMatrix[1][3] * duplicateMatrix->mMatrix[3][1] * duplicateMatrix->mMatrix[2][2];

		inverse->mMatrix[0][1] = -duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[2][2] * duplicateMatrix->mMatrix[3][3] +
								  duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[3][2] * duplicateMatrix->mMatrix[2][3] +
						       	  duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[3][3] -
								  duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[1][3] * duplicateMatrix->mMatrix[2][3] -
								  duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[3][2] +
								  duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[1][3] * duplicateMatrix->mMatrix[2][2];

		inverse->mMatrix[0][2] = duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[3][3] -
								 duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[3][2] * duplicateMatrix->mMatrix[1][3] -
								 duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[3][3] +
								 duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[3][1] * duplicateMatrix->mMatrix[1][3] +
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[3][2] -
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[3][1] * duplicateMatrix->mMatrix[1][2];

		inverse->mMatrix[0][3] = -duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[2][3] +
								  duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[2][2] * duplicateMatrix->mMatrix[1][3] +
								  duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[2][3] -
								  duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[1][3] -
								  duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[2][2] +
								  duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[1][2];

		inverse->mMatrix[1][0] = -duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[2][2] * duplicateMatrix->mMatrix[3][3] +
								  duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[3][2]* duplicateMatrix->mMatrix[2][3] +
								  duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][3] -
								  duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][3] -
								  duplicateMatrix->mMatrix[1][3] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][2]+
								  duplicateMatrix->mMatrix[1][3] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][2];

		inverse->mMatrix[1][1] = duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[2][2] * duplicateMatrix->mMatrix[3][3] -
								 duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[3][2] * duplicateMatrix->mMatrix[2][3] -
								 duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][3] +
								 duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][3] +
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][2] -
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][2];

		inverse->mMatrix[1][2] = -duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[3][3] +
								  duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[3][2] * duplicateMatrix->mMatrix[1][3] +
								  duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[3][3] -
								  duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[1][3] -
								  duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[3][2] +
								  duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[1][2];

		inverse->mMatrix[1][3] = duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[2][3] -
								 duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[2][2] * duplicateMatrix->mMatrix[1][3] -
								 duplicateMatrix->mMatrix[0][8] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[2][3] +
								 duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[1][3] +
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[2][2] -
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[1][2];

		inverse->mMatrix[2][0] = duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[3][3] -
								 duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[2][3] -
								 duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][3] +
								 duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][3] +
								 duplicateMatrix->mMatrix[1][3] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][1] -
								 duplicateMatrix->mMatrix[1][3] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][1];

		inverse->mMatrix[2][1] = -duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[3][3] +
								  duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[3][1] * duplicateMatrix->mMatrix[2][3] +
								  duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][3] -
								  duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][3] -
								  duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][1] +
								  duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][1];

		inverse->mMatrix[2][2] = duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[3][3] -
								 duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[3][1] * duplicateMatrix->mMatrix[1][3] -
								 duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[3][3] +
								 duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[1][3] +
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[3][1] -
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[1][1];

		inverse->mMatrix[2][3]= -duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[2][3] +
								 duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[1][3] +
								 duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[2][3] -
								 duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[1][3] -
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[2][1] +
								 duplicateMatrix->mMatrix[0][3] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[1][1];

		inverse->mMatrix[3][0] = -duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[3][2] +
								  duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[3][1] * duplicateMatrix->mMatrix[2][2] +
								  duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][2] -
								  duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][2] -
								  duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][1] +
								  duplicateMatrix->mMatrix[1][2] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][1];

		inverse->mMatrix[3][1] = duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[3][2] -
							     duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[3][1] * duplicateMatrix->mMatrix[2][2] -
								 duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][2] +
								 duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][2] +
								 duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[3][1] -
								 duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[2][1];

		inverse->mMatrix[3][2] = -duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[3][2] +
								  duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[3][1] * duplicateMatrix->mMatrix[1][2] +
								  duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[3][2] -
								  duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[1][2] -
								  duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[3][1] +
								  duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[3][0] * duplicateMatrix->mMatrix[1][1];

		inverse->mMatrix[3][3] = duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[1][1] * duplicateMatrix->mMatrix[2][2] -
								 duplicateMatrix->mMatrix[0][0] * duplicateMatrix->mMatrix[2][1] * duplicateMatrix->mMatrix[1][2] -
								 duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[2][2] +
							     duplicateMatrix->mMatrix[0][1] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[1][2] +
								 duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[1][0] * duplicateMatrix->mMatrix[2][1] -
							     duplicateMatrix->mMatrix[0][2] * duplicateMatrix->mMatrix[2][0] * duplicateMatrix->mMatrix[1][1];

		determinant = duplicateMatrix->mMatrix[0][0] * inverse->mMatrix[0][0] + 
					  duplicateMatrix->mMatrix[1][0] * inverse->mMatrix[0][1] + 
				      duplicateMatrix->mMatrix[2][0] * inverse->mMatrix[0][2] + 
					  duplicateMatrix->mMatrix[3][0] * inverse->mMatrix[0][3];
	
		if (determinant != 0)
		{
			determinant = 1.0f / determinant;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					inverse[i][j] = inverse[i][j] * determinant;
				}
			}

			return *inverse;
		}
	}

	float& matrix_4::operator[](const int pRightSide)
	{
		int row = pRightSide % 4;
		int column = pRightSide / 4;

		return mMatrix[row][column];
	}

	std::ostream& operator<<(std::ostream& pOstream, matrix_4 pMatrix)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				pOstream << pMatrix.mMatrix[i][j] << " ";
			}
			pOstream << "\n";
		}

		return pOstream;
	}

	vector_3 matrix_4::get_angle()
	{
		float yaw, pitch, roll;

		if(mMatrix[0][0] == 1.0f || mMatrix[0][0] == -1.0f)
		{
			yaw = atan2f(mMatrix[0][2], mMatrix[2][3]);
			pitch = 0.0f;
			roll = 0.0f;
		}
		else
		{
			yaw = atan2f(-mMatrix[2][1], mMatrix[0][0]);
			pitch = asinf(mMatrix[1][0]);
			roll = atan2f(-mMatrix[1][2], mMatrix[1][1]);
		}

		//yaw degree range (-180, 180)
		if(yaw < -180.0f)
		{
			yaw = (yaw + 180.0f) * -1;
		}
		if (yaw > 180.0f)
		{
			yaw = (yaw - 180.0f) * -1;
		}

		//pitch degree range (-180, 180)
		if (pitch < -180.0f)
		{
			pitch = (pitch + 180.0f) * -1;
		}
		if (pitch > 180.0f)
		{
			pitch = (pitch - 180.0f) * -1;
		}

		//roll degree range (-180, 180)
		if (roll < -180.0f)
		{
			roll = (roll + 180.0f) * -1;
		}
		if (roll > 180.0f)
		{
			roll = (roll - 180.0f) * -1;
		}

		return vector_3(yaw, pitch, roll);
	}

	void matrix_4::translate(vector_4 *pVector)
	{
		pVector->mX = (mMatrix[0][0] * pVector->mX) + 
					  (mMatrix[0][1] * pVector->mY) + 
					  (mMatrix[0][2] * pVector->mZ) + 
					  (mMatrix[0][3] * pVector->mW);

		pVector->mY = (mMatrix[1][0] * pVector->mX) +
					  (mMatrix[1][1] * pVector->mY) +
					  (mMatrix[1][2] * pVector->mZ) +
					  (mMatrix[1][3] * pVector->mW);

		pVector->mZ = (mMatrix[2][0] * pVector->mX) +
					  (mMatrix[2][1] * pVector->mY) +
					  (mMatrix[2][2] * pVector->mZ) +
					  (mMatrix[2][3] * pVector->mW);

		pVector->mW = (mMatrix[3][0] * pVector->mX) +
					  (mMatrix[3][1] * pVector->mY) +
					  (mMatrix[3][2] * pVector->mZ) +
					  (mMatrix[3][3] * pVector->mW);
	}	

	matrix_4 matrix_4::operator+(const matrix_4 pRightSide)
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

	matrix_4& matrix_4::operator+=(const matrix_4 pRightSide)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[i][j] += pRightSide.mMatrix[i][j];
			}
		}

		return *this;
	}

	matrix_4 matrix_4::operator-(const matrix_4 pRightSide)
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

	matrix_4& matrix_4::operator-=(const matrix_4 pRightSide)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[i][j] -= pRightSide.mMatrix[i][j];
			}
		}

		return *this;
	}

	matrix_4 matrix_4::operator*(const matrix_4 pRightSide)
	{
		matrix_4 matrix;

		//product of the first row
		for (int i = 0; i < 4; i++)
		{
			matrix.mMatrix[0][i] = 0;
			for (int j = 0; j < 4; j++)
			{
				matrix.mMatrix[0][i] += matrix.mMatrix[0][j] * pRightSide.mMatrix[j][i];
			}
		}

		//product of the second row
		for (int i = 0; i < 4; i++)
		{
			matrix.mMatrix[1][i] = 0;
			for (int j = 0; j < 4; j++)
			{
				matrix.mMatrix[1][i] += matrix.mMatrix[1][j] * pRightSide.mMatrix[j][i];
			}
		}

		//product of the third row
		for (int i = 0; i < 4; i++)
		{
			matrix.mMatrix[2][i] = 0;
			for (int j = 0; j < 4; j++)
			{
				matrix.mMatrix[2][i] += matrix.mMatrix[2][j] * pRightSide.mMatrix[j][i];
			}
		}

		//product of the fourth row
		for (int i = 0; i < 4; i++)
		{
			matrix.mMatrix[3][i] = 0;
			for (int j = 0; j < 4; j++)
			{
				matrix.mMatrix[3][i] += matrix.mMatrix[3][j] * pRightSide.mMatrix[j][i];
			}
		}

		return matrix;
	}

	matrix_4& matrix_4::operator*=(const matrix_4 pRightSide)
	{
		//product of the first row
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[0][i] *= pRightSide.mMatrix[j][i];
			}
		}

		//product of the second row
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[1][i] *= pRightSide.mMatrix[j][i];
			}
		}

		//product of the third row
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[2][i] *= pRightSide.mMatrix[j][i];
			}
		}

		//product of the fourth row
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[3][i] *= pRightSide.mMatrix[j][i];
			}
		}

		return *this;
	}

	matrix_4 matrix_4::operator/(matrix_4 pRightSide)
	{
		matrix_4 matrix;

		matrix = *this *  pRightSide.invert();
		
		return matrix;
	}

	matrix_4& matrix_4::operator/=(matrix_4 pRightSide)
	{
		*this *= pRightSide.invert();

		return *this;
	}

	matrix_4& matrix_4::operator=(matrix_4 pRightSide)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix[i][j] = pRightSide.mMatrix[i][j];
			}
		}

		return *this;
	}
}
