#include "matrix_4.hpp"

namespace engine
{
	namespace math
	{
		matrix_4::matrix_4()
		{
			mMatrix[0] = 1;
			mMatrix[1] = 0;
			mMatrix[2] = 0;
			mMatrix[3] = 0;
			mMatrix[4] = 0;
			mMatrix[5] = 1;
			mMatrix[6] = 0;
			mMatrix[7] = 0;
			mMatrix[8] = 0;
			mMatrix[9] = 0;
			mMatrix[10] = 1;
			mMatrix[11] = 0;
			mMatrix[12] = 0;
			mMatrix[13] = 0;
			mMatrix[14] = 0;
			mMatrix[15] = 1;
		}

		matrix_4::matrix_4(float pArray[16])
		{
			//matrix[row][column]
			//first column
			mMatrix[0] = pArray[0];
			mMatrix[1] = pArray[1];
			mMatrix[2] = pArray[2];
			mMatrix[3] = pArray[3];

			//second column
			mMatrix[4] = pArray[4];
			mMatrix[5] = pArray[5];
			mMatrix[6] = pArray[6];
			mMatrix[7] = pArray[7];

			//third column
			mMatrix[8] = pArray[8];
			mMatrix[9] = pArray[9];
			mMatrix[10] = pArray[10];
			mMatrix[11] = pArray[11];

			//fourth column
			mMatrix[12] = pArray[12];
			mMatrix[13] = pArray[13];
			mMatrix[14] = pArray[14];
			mMatrix[15] = pArray[15];
		}

		matrix_4::matrix_4(float pFristValue, float pSecondValue, float pThirdValue, float pFourthValue,
			float pFifthValue, float pSixthValue, float pSeventhValue, float pEighthValue,
			float pNinthValue, float pTenthValue, float pEleventhValue, float pTwelfthValue,
			float pThirteenthValue, float pFourteenthValue, float pFifteenthValue, float pSixteenthValue)
		{
			//matrix[row][column]
			//first column
			mMatrix[0] = pFristValue;
			mMatrix[1] = pSecondValue;
			mMatrix[2] = pThirdValue;
			mMatrix[3] = pFourthValue;

			//second column
			mMatrix[4] = pFifthValue;
			mMatrix[5] = pSixthValue;
			mMatrix[6] = pSeventhValue;
			mMatrix[7] = pEighthValue;

			//third column
			mMatrix[8] = pNinthValue;
			mMatrix[9] = pTenthValue;
			mMatrix[10] = pEleventhValue;
			mMatrix[11] = pTwelfthValue;

			//fourth column
			mMatrix[12] = pThirteenthValue;
			mMatrix[13] = pFourteenthValue;
			mMatrix[14] = pFifteenthValue;
			mMatrix[15] = pSixteenthValue;
		}

		float *matrix_4::get_matrix()
		{
			return mMatrix;
		}

		float *matrix_4::get_matrix_pointer()
		{
			return &mMatrix[0];
		}

		float *matrix_4::get_matrix_row(int pRowIndex)
		{
			float matrixRow[4];

			matrixRow[0] = mMatrix[pRowIndex];
			matrixRow[1] = mMatrix[pRowIndex + 1];
			matrixRow[2] = mMatrix[pRowIndex + 2];
			matrixRow[3] = mMatrix[pRowIndex + 3];

			return matrixRow;
		}

		float *matrix_4::get_matrix_column(int pColumnIndex)
		{
			float matrixColumn[4];

			matrixColumn[0] = mMatrix[pColumnIndex];
			matrixColumn[1] = mMatrix[pColumnIndex + 1];
			matrixColumn[2] = mMatrix[pColumnIndex + 2];
			matrixColumn[3] = mMatrix[pColumnIndex + 3];

			return matrixColumn;
		}

		void matrix_4::assign_matrix(float pMatrix[])
		{
			pMatrix[0] = mMatrix[0];
			pMatrix[1] = mMatrix[1];
			pMatrix[2] = mMatrix[2];
			pMatrix[3] = mMatrix[3];
			pMatrix[4] = mMatrix[4];
			pMatrix[5] = mMatrix[5];
			pMatrix[6] = mMatrix[6];
			pMatrix[7] = mMatrix[7];
			pMatrix[8] = mMatrix[8];
			pMatrix[9] = mMatrix[9];
			pMatrix[10] = mMatrix[10];
			pMatrix[11] = mMatrix[11];
			pMatrix[12] = mMatrix[12];
			pMatrix[13] = mMatrix[13];
			pMatrix[14] = mMatrix[14];
			pMatrix[15] = mMatrix[15];
		}

		void matrix_4::set_identity()
		{
			mMatrix[0] = 1;
			mMatrix[1] = 0;
			mMatrix[2] = 0;
			mMatrix[3] = 0;
			mMatrix[4] = 0;
			mMatrix[5] = 1;
			mMatrix[6] = 0;
			mMatrix[7] = 0;
			mMatrix[8] = 0;
			mMatrix[9] = 0;
			mMatrix[10] = 1;
			mMatrix[11] = 0;
			mMatrix[12] = 0;
			mMatrix[13] = 0;
			mMatrix[14] = 0;
			mMatrix[15] = 1;
		}

		matrix_4 matrix_4::get_transpose()
		{
			matrix_4 transposeMatrix;

			//first column
			transposeMatrix[0] = mMatrix[0];
			transposeMatrix[1] = mMatrix[1];
			transposeMatrix[2] = mMatrix[2];
			transposeMatrix[3] = mMatrix[3];

			//second column
			transposeMatrix[4] = mMatrix[4];
			transposeMatrix[5] = mMatrix[5];
			transposeMatrix[6] = mMatrix[6];
			transposeMatrix[7] = mMatrix[7];

			//third column
			transposeMatrix[8] = mMatrix[8];
			transposeMatrix[9] = mMatrix[9];
			transposeMatrix[10] = mMatrix[10];
			transposeMatrix[11] = mMatrix[11];

			//fourth column
			transposeMatrix[12] = mMatrix[12];
			transposeMatrix[13] = mMatrix[13];
			transposeMatrix[14] = mMatrix[14];
			transposeMatrix[15] = mMatrix[15];

			return transposeMatrix;
		}

		float matrix_4::get_matrix_value(int pRowIndex, int pColumnIndex)
		{
			return mMatrix[pColumnIndex * 4 + pRowIndex];
		}

		matrix_4 matrix_4::invert()
		{
			float determinant;
			matrix_4 *duplicateMatrix;
			matrix_4 *inverse = new matrix_4();
			duplicateMatrix = this;

			inverse->mMatrix[0] = duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[10] * duplicateMatrix->mMatrix[15] -
								  duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[14] -
								  duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[15] +
							   	  duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[14] +
							   	  duplicateMatrix->mMatrix[13] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[11] -
				                  duplicateMatrix->mMatrix[13] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[10];

			inverse->mMatrix[4] = -duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[10] * duplicateMatrix->mMatrix[15] +
								   duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[11] * duplicateMatrix->mMatrix[14] +
								   duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[15] -
				                   duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[13] * duplicateMatrix->mMatrix[14] -
				                   duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[11] +
				                   duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[13] * duplicateMatrix->mMatrix[10];

			inverse->mMatrix[8] = duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[15] -
				                  duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[11] * duplicateMatrix->mMatrix[13] -
				                  duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[15] +
				                  duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[13] +
				                  duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[1] -
				                  duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[9];

			inverse->mMatrix[12] = -duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[14] +
				                    duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[10] * duplicateMatrix->mMatrix[13] +
				                    duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[14] -
			                       	duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[13] -
			                     	duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[10] +
			                      	duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[9];

			inverse->mMatrix[1] = -duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[10] * duplicateMatrix->mMatrix[15] +
				                   duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[11] * duplicateMatrix->mMatrix[14] +
				                   duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[15] -
			                       duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[14] -
				                   duplicateMatrix->mMatrix[13] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[11] +
				                   duplicateMatrix->mMatrix[13] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[10];

			inverse->mMatrix[5] = duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[10] * duplicateMatrix->mMatrix[15] -
				                  duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[11] * duplicateMatrix->mMatrix[14] -
				                  duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[15] +
			                   	  duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[14] +
				                  duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[11] -
				                  duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[10];

			inverse->mMatrix[9] = -duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[15] +
								   duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[11] * duplicateMatrix->mMatrix[13] +
							  	   duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[15] -
				                   duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[13] -
				                   duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[11] +
				                   duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[9];

			inverse->mMatrix[13] = duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[14] -
								   duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[10] * duplicateMatrix->mMatrix[13] -
								   duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[14] +
								   duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[13] +
								   duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[10] -
								   duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[9];

			inverse->mMatrix[2] = duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[15] -
								  duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[14] -
							   	  duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[15] +
								  duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[14] +
								  duplicateMatrix->mMatrix[13] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[7] -
								  duplicateMatrix->mMatrix[13] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[6];

			inverse->mMatrix[6] = -duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[15] +
								   duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[14] +
								   duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[15] -
								   duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[14] -
								   duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[7] +
								   duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[6];

			inverse->mMatrix[10] = duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[15] -
							   	   duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[13] -
				                   duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[15] +
				                   duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[13] +
				                   duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[7] -
				                   duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[5];

			inverse->mMatrix[14] = -duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[14] +
				                    duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[13] +
				                    duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[14] -
				                    duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[13] -
				                    duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[6] +
				                    duplicateMatrix->mMatrix[12] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[5];

			inverse->mMatrix[3] = -duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[11] +
			                       duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[10] +
				                   duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[11] -
				                   duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[10] -
				                   duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[7] +
				                   duplicateMatrix->mMatrix[9] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[6];

			inverse->mMatrix[7] = duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[11] -
				                  duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[10] -
				                  duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[11] +
				                  duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[10] +
				                  duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[7] -
			                   	  duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[6];

			inverse->mMatrix[11] = -duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[11] +
				                    duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[7] * duplicateMatrix->mMatrix[9] +
				                    duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[11] -
				                    duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[9] -
				                    duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[7] +
				                    duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[3] * duplicateMatrix->mMatrix[5];

			inverse->mMatrix[15] = duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[5] * duplicateMatrix->mMatrix[10] -
			                 	   duplicateMatrix->mMatrix[0] * duplicateMatrix->mMatrix[6] * duplicateMatrix->mMatrix[9] -
				                   duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[10] +
				                   duplicateMatrix->mMatrix[4] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[9] +
			                       duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[1] * duplicateMatrix->mMatrix[6] -
				                   duplicateMatrix->mMatrix[8] * duplicateMatrix->mMatrix[2] * duplicateMatrix->mMatrix[5];

			determinant = duplicateMatrix->mMatrix[0] * inverse->mMatrix[0] +
				          duplicateMatrix->mMatrix[1] * inverse->mMatrix[4] +
				          duplicateMatrix->mMatrix[2] * inverse->mMatrix[8] +
				          duplicateMatrix->mMatrix[3] * inverse->mMatrix[12];

			if (determinant != 0)
			{
				determinant = 1.0f / determinant;

				inverse->mMatrix[0] = inverse->mMatrix[0] * determinant;
				inverse->mMatrix[1] = inverse->mMatrix[1] * determinant;
				inverse->mMatrix[2] = inverse->mMatrix[2] * determinant;
				inverse->mMatrix[3] = inverse->mMatrix[3] * determinant;
				inverse->mMatrix[4] = inverse->mMatrix[4] * determinant;
				inverse->mMatrix[5] = inverse->mMatrix[5] * determinant;
				inverse->mMatrix[6] = inverse->mMatrix[6] * determinant;
				inverse->mMatrix[7] = inverse->mMatrix[7] * determinant;
				inverse->mMatrix[8] = inverse->mMatrix[8] * determinant;
				inverse->mMatrix[9] = inverse->mMatrix[9] * determinant;
				inverse->mMatrix[10] = inverse->mMatrix[10] * determinant;
				inverse->mMatrix[11] = inverse->mMatrix[11] * determinant;
				inverse->mMatrix[12] = inverse->mMatrix[12] * determinant;
				inverse->mMatrix[13] = inverse->mMatrix[13] * determinant;
				inverse->mMatrix[14] = inverse->mMatrix[14] * determinant;
				inverse->mMatrix[15] = inverse->mMatrix[15] * determinant;

				return *inverse;
			}
			else
			{
				return NULL;
			}
		}

		float& matrix_4::operator[](const int pRightSide)
		{
			return mMatrix[pRightSide];
		}

		std::ostream& operator<<(std::ostream& pOstream, matrix_4 pMatrix)
		{
			pOstream << pMatrix[0] << " ";
			pOstream << pMatrix[1] << " ";
			pOstream << pMatrix[2] << " ";
			pOstream << pMatrix[3] << " ";
			pOstream << "\n";
			pOstream << pMatrix[4] << " ";
			pOstream << pMatrix[5] << " ";
			pOstream << pMatrix[6] << " ";
			pOstream << pMatrix[7] << " ";
			pOstream << "\n";
			pOstream << pMatrix[8] << " ";
			pOstream << pMatrix[9] << " ";
			pOstream << pMatrix[10] << " ";
			pOstream << pMatrix[11] << " ";
			pOstream << "\n";
			pOstream << pMatrix[12] << " ";
			pOstream << pMatrix[13] << " ";
			pOstream << pMatrix[14] << " ";
			pOstream << pMatrix[15] << " ";
			pOstream << "\n";

			return pOstream;
		}

		vector_3 matrix_4::get_angle()
		{
			float yaw, pitch, roll;

			if (mMatrix[0] == 1.0f || mMatrix[0] == -1.0f)
			{
				yaw = atan2f(mMatrix[8], mMatrix[14]);
				pitch = 0.0f;
				roll = 0.0f;
			}
			else
			{
				yaw = atan2f(-mMatrix[6], mMatrix[0]);
				pitch = asinf(mMatrix[1]);
				roll = atan2f(-mMatrix[9], mMatrix[5]);
			}

			//yaw degree range (-180, 180)
			if (yaw < -180.0f)
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

		void matrix_4::translate_vector(vector_4 pVector)
		{
			matrix_4 translationMatrix;

			translationMatrix.mMatrix[12] = pVector.mX;
			translationMatrix.mMatrix[13] = pVector.mY;
			translationMatrix.mMatrix[14] = pVector.mZ;

			*this = *this * translationMatrix;
		}

		void matrix_4::rotate_from_degrees(float pDegrees)
		{
			math_utilities mathUtilities;

			float angleInRadians = mathUtilities.degrees_to_radians(pDegrees);

			this->rotate_z(angleInRadians);
		}

		void matrix_4::rotate_from_radians(float pRadians)
		{
			this->rotate_z(pRadians);
		}

		void matrix_4::rotate_x(float pRadians)
		{
			matrix_4 rotationMatrix;

			rotationMatrix[5] = cos(-pRadians);
			rotationMatrix[6] = -sin(-pRadians);
			rotationMatrix[9] = sin(-pRadians);
			rotationMatrix[10] = cos(-pRadians);

			*this = *this * rotationMatrix;
		}

		void matrix_4::rotate_y(float pRadians)
		{
			matrix_4 rotationMatrix;

			rotationMatrix[0] = cos(-pRadians);
			rotationMatrix[2] = sin(-pRadians);
			rotationMatrix[8] = -sin(-pRadians);
			rotationMatrix[10] = cos(-pRadians);

			*this = rotationMatrix * *this;
		}

		void matrix_4::rotate_z(float pRadians)
		{
			matrix_4 rotationMatrix;

			rotationMatrix[0] = cos(-pRadians);
			rotationMatrix[1] = -sin(-pRadians);
			rotationMatrix[4] = sin(-pRadians);
			rotationMatrix[5] = cos(-pRadians);

			*this = *this * rotationMatrix;
		}

		void matrix_4::transform(matrix_4 pTranslation, matrix_4 pRotation, matrix_4 pScale)
		{
			*this = pTranslation * pRotation * pScale;
		}

		matrix_4 matrix_4::operator+(matrix_4 pRightSide)
		{
			matrix_4 matrix;

			matrix[0] = mMatrix[0] + pRightSide[0];
			matrix[1] = mMatrix[1] + pRightSide[1];
			matrix[2] = mMatrix[2] + pRightSide[2];
			matrix[3] = mMatrix[3] + pRightSide[3];
			matrix[4] = mMatrix[4] + pRightSide[4];
			matrix[5] = mMatrix[5] + pRightSide[5];
			matrix[6] = mMatrix[6] + pRightSide[6];
			matrix[7] = mMatrix[7] + pRightSide[7];
			matrix[8] = mMatrix[8] + pRightSide[8];
			matrix[9] = mMatrix[9] + pRightSide[9];
			matrix[10] = mMatrix[10] + pRightSide[10];
			matrix[11] = mMatrix[11] + pRightSide[11];
			matrix[12] = mMatrix[12] + pRightSide[12];
			matrix[13] = mMatrix[13] + pRightSide[13];
			matrix[14] = mMatrix[14] + pRightSide[14];
			matrix[15] = mMatrix[15] + pRightSide[15];

			return matrix;
		}

		matrix_4& matrix_4::operator+=(matrix_4 pRightSide)
		{
			mMatrix[0] += pRightSide[0];
			mMatrix[1] += pRightSide[1];
			mMatrix[2] += pRightSide[2];
			mMatrix[3] += pRightSide[3];
			mMatrix[4] += pRightSide[4];
			mMatrix[5] += pRightSide[5];
			mMatrix[6] += pRightSide[6];
			mMatrix[7] += pRightSide[7];
			mMatrix[8] += pRightSide[8];
			mMatrix[9] += pRightSide[9];
			mMatrix[10] += pRightSide[10];
			mMatrix[11] += pRightSide[11];
			mMatrix[12] += pRightSide[12];
			mMatrix[13] += pRightSide[13];
			mMatrix[14] += pRightSide[14];
			mMatrix[15] += pRightSide[15];


			return *this;
		}

		matrix_4 matrix_4::operator-(matrix_4 pRightSide)
		{
			matrix_4 matrix;

			matrix[0] = mMatrix[0] - pRightSide[0];
			matrix[1] = mMatrix[1] - pRightSide[1];
			matrix[2] = mMatrix[2] - pRightSide[2];
			matrix[3] = mMatrix[3] - pRightSide[3];
			matrix[4] = mMatrix[4] - pRightSide[4];
			matrix[5] = mMatrix[5] - pRightSide[5];
			matrix[6] = mMatrix[6] - pRightSide[6];
			matrix[7] = mMatrix[7] - pRightSide[7];
			matrix[8] = mMatrix[8] - pRightSide[8];
			matrix[9] = mMatrix[9] - pRightSide[9];
			matrix[10] = mMatrix[10] - pRightSide[10];
			matrix[11] = mMatrix[11] - pRightSide[11];
			matrix[12] = mMatrix[12] - pRightSide[12];
			matrix[13] = mMatrix[13] - pRightSide[13];
			matrix[14] = mMatrix[14] - pRightSide[14];
			matrix[15] = mMatrix[15] - pRightSide[15];


			return matrix;
		}

		matrix_4& matrix_4::operator-=(matrix_4 pRightSide)
		{
			mMatrix[0] -= pRightSide[0];
			mMatrix[1] -= pRightSide[1];
			mMatrix[2] -= pRightSide[2];
			mMatrix[3] -= pRightSide[3];
			mMatrix[4] -= pRightSide[4];
			mMatrix[5] -= pRightSide[5];
			mMatrix[6] -= pRightSide[6];
			mMatrix[7] -= pRightSide[7];
			mMatrix[8] -= pRightSide[8];
			mMatrix[9] -= pRightSide[9];
			mMatrix[10] -= pRightSide[10];
			mMatrix[11] -= pRightSide[11];
			mMatrix[12] -= pRightSide[12];
			mMatrix[13] -= pRightSide[13];
			mMatrix[14] -= pRightSide[14];
			mMatrix[15] -= pRightSide[15];
			return *this;
		}

		matrix_4 matrix_4::operator*(matrix_4& pRightSide)
		{
			matrix_4 matrix(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
			//first column
			matrix[0] = mMatrix[0] * pRightSide[0] + mMatrix[4] * pRightSide[1] +
				mMatrix[8] * pRightSide[2] + mMatrix[12] * pRightSide[3];
			matrix[1] = mMatrix[0] * pRightSide[4] + mMatrix[4] * pRightSide[5] +
				mMatrix[8] * pRightSide[6] + mMatrix[12] * pRightSide[7];
			matrix[2] = mMatrix[0] * pRightSide[8] + mMatrix[4] * pRightSide[9] +
				mMatrix[8] * pRightSide[10] + mMatrix[12] * pRightSide[11];
			matrix[3] = mMatrix[0] * pRightSide[12] + mMatrix[4] * pRightSide[13] +
				mMatrix[8] * pRightSide[14] + mMatrix[12] * pRightSide[15];
			//second column
			matrix[4] = mMatrix[1] * pRightSide[0] + mMatrix[5] * pRightSide[1] +
				mMatrix[9] * pRightSide[2] + mMatrix[13] * pRightSide[3];
			matrix[5] = mMatrix[1] * pRightSide[4] + mMatrix[5] * pRightSide[5] +
				mMatrix[9] * pRightSide[6] + mMatrix[13] * pRightSide[7];
			matrix[6] = mMatrix[1] * pRightSide[8] + mMatrix[5] * pRightSide[9] +
				mMatrix[9] * pRightSide[10] + mMatrix[13] * pRightSide[11];
			matrix[7] = mMatrix[1] * pRightSide[12] + mMatrix[5] * pRightSide[13] +
				mMatrix[9] * pRightSide[14] + mMatrix[13] * pRightSide[15];
			//third column
			matrix[8] = mMatrix[2] * pRightSide[0] + mMatrix[6] * pRightSide[1] +
				mMatrix[10] * pRightSide[2] + mMatrix[14] * pRightSide[3];
			matrix[9] = mMatrix[2] * pRightSide[4] + mMatrix[6] * pRightSide[5] +
				mMatrix[10] * pRightSide[6] + mMatrix[14] * pRightSide[7];
			matrix[10] = mMatrix[2] * pRightSide[8] + mMatrix[6] * pRightSide[9] +
				mMatrix[10] * pRightSide[10] + mMatrix[14] * pRightSide[11];
			matrix[11] = mMatrix[2] * pRightSide[12] + mMatrix[6] * pRightSide[13] +
				mMatrix[10] * pRightSide[14] + mMatrix[14] * pRightSide[15];
			//fourth column
			matrix[12] = mMatrix[3] * pRightSide[0] + mMatrix[7] * pRightSide[1] +
				mMatrix[11] * pRightSide[2] + mMatrix[15] * pRightSide[3];
			matrix[13] = mMatrix[3] * pRightSide[4] + mMatrix[7] * pRightSide[5] +
				mMatrix[11] * pRightSide[6] + mMatrix[15] * pRightSide[7];
			matrix[14] = mMatrix[3] * pRightSide[8] + mMatrix[7] * pRightSide[9] +
				mMatrix[11] * pRightSide[10] + mMatrix[15] * pRightSide[11];
			matrix[15] = mMatrix[3] * pRightSide[12] + mMatrix[7] * pRightSide[13] +
				mMatrix[11] * pRightSide[14] + mMatrix[15] * pRightSide[15];

			return matrix;
		}

		matrix_4 matrix_4::operator/(matrix_4 pRightSide)
		{
			matrix_4 matrix;

			matrix = *this *  pRightSide.invert();

			return matrix;
		}

		matrix_4& matrix_4::operator=(matrix_4 pRightSide)
		{
			mMatrix[0] = pRightSide[0];
			mMatrix[1] = pRightSide[1];
			mMatrix[2] = pRightSide[2];
			mMatrix[3] = pRightSide[3];
			mMatrix[4] = pRightSide[4];
			mMatrix[5] = pRightSide[5];
			mMatrix[6] = pRightSide[6];
			mMatrix[7] = pRightSide[7];
			mMatrix[8] = pRightSide[8];
			mMatrix[9] = pRightSide[9];
			mMatrix[10] = pRightSide[10];
			mMatrix[11] = pRightSide[11];
			mMatrix[12] = pRightSide[12];
			mMatrix[13] = pRightSide[13];
			mMatrix[14] = pRightSide[14];
			mMatrix[15] = pRightSide[15];
			return *this;
		}

		vector_4 operator*(matrix_4 pLeftSide, vector_4 pRightSide)
		{
			vector_4 result;

<<<<<<< HEAD
			result.mX = pLeftSide[0]  * pRightSide.mX + 
						pLeftSide[4]  * pRightSide.mY + 
						pLeftSide[8]  * pRightSide.mZ +
						pLeftSide[12] * pRightSide.mW;

			result.mY = pLeftSide[1]  * pRightSide.mX + 
						pLeftSide[5]  * pRightSide.mY + 
						pLeftSide[9]  * pRightSide.mZ +
						pLeftSide[13] * pRightSide.mW;

			result.mZ = pLeftSide[2]  * pRightSide.mX + 
						pLeftSide[6]  * pRightSide.mY +
						pLeftSide[10] * pRightSide.mZ +
						pLeftSide[14] * pRightSide.mW;

			result.mX = pLeftSide[3]  * pRightSide.mX +
						pLeftSide[7]  * pRightSide.mY + 
						pLeftSide[11] * pRightSide.mZ +
						pLeftSide[15] * pRightSide.mW;
=======
			result.mX = pLeftSide[0] * pRightSide.mX +
				pLeftSide[4] * pRightSide.mY +
				pLeftSide[8] * pRightSide.mZ +
				pLeftSide[12] * pRightSide.mW;

			result.mY = pLeftSide[1] * pRightSide.mX +
				pLeftSide[5] * pRightSide.mY +
				pLeftSide[9] * pRightSide.mZ +
				pLeftSide[13] * pRightSide.mW;

			result.mZ = pLeftSide[2] * pRightSide.mX +
				pLeftSide[6] * pRightSide.mY +
				pLeftSide[10] * pRightSide.mZ +
				pLeftSide[14] * pRightSide.mW;

			result.mX = pLeftSide[3] * pRightSide.mX +
				pLeftSide[7] * pRightSide.mY +
				pLeftSide[11] * pRightSide.mZ +
				pLeftSide[15] * pRightSide.mW;
>>>>>>> feature/lvl_generator

			return result;
		}

		void matrix_4::make_ortho(const float &pMinimumXAxis, const float &pMaximumXAxis, const float &pMinimumYAxis,
								  const float &pMaximumYAxis, const float &pMinimumZAxis, const float &pMaximumZAxis)
		{
<<<<<<< HEAD
			//setting identity matrix, saves 10 lines of codes...
			set_identity();
			//setting inverse of the difference, save 3 divisions...
			float inverseXAxesDifference = 1 / (pMaximumXAxis - pMinimumXAxis);
			float inverseYAxesDifference = 1 / (pMaximumYAxis - pMinimumYAxis);
			float inverseZAxesDifference = 1 / (pMaximumZAxis - pMinimumZAxis);
	
=======
			float inverseXAxesDifference = 1 / (pMaximumXAxis - pMinimumXAxis);
			float inverseYAxesDifference = 1 / (pMaximumYAxis - pMinimumYAxis);
			float inverseZAxesDifference = 1 / (pMaximumZAxis - pMinimumZAxis);

>>>>>>> feature/lvl_generator
			mMatrix[0] = 2.0f * inverseXAxesDifference;
			mMatrix[5] = 2.0f * inverseYAxesDifference;
			mMatrix[10] = -2.0f * inverseZAxesDifference;
			mMatrix[12] = -(pMaximumXAxis + pMinimumXAxis) * inverseXAxesDifference;
			mMatrix[13] = -(pMaximumYAxis + pMinimumYAxis) * inverseYAxesDifference;
			mMatrix[14] = -(pMaximumZAxis + pMinimumZAxis) * inverseZAxesDifference;
		}

		void matrix_4::make_perspective(const float &pFieldOfView, const float &pNearClippingPlane, const float &pFarClippingPlane
			, const float& pScreenAspect)
		{
			math_utilities mathMaster;
			//scale based on field of view, used mathmaster for angles managing
			//operation pi/180 can be used with degrees_to_radians with 1 as angle
<<<<<<< HEAD
			float scale = 1 / (tan(pFieldOfView * 0.5) * mathMaster.degrees_to_radians(1));
	
			float inverseClippingPlaneDifference = 1 / (pFarClippingPlane - pNearClippingPlane);

			mMatrix[0] = scale;
=======
			float scale = (float) (1.0f / (tan(mathMaster.degrees_to_radians(pFieldOfView * 0.5f))));

			float inverseClippingPlaneDifference = 1.0f / (pFarClippingPlane - pNearClippingPlane);

			mMatrix[0] = scale * pScreenAspect;
>>>>>>> feature/lvl_generator
			mMatrix[5] = scale;
			mMatrix[10] = -pFarClippingPlane * inverseClippingPlaneDifference;
			mMatrix[11] = -1;
			mMatrix[14] = -pFarClippingPlane * pNearClippingPlane * inverseClippingPlaneDifference;
			mMatrix[15] = 0;
		}

		void matrix_4::make_look_at(vector_3 pLookingPosition, vector_3 pTargetPosition)
		{
			vector_3 forward(pLookingPosition - pTargetPosition);
			forward.normalize();
			vector_3 tmp(0.0f, 1.0f, 0.0f);
			tmp.normalize();
			vector_3 right;
			right = tmp.cross_product(tmp, forward);
			vector_3 up;
			up = tmp.cross_product(forward, right);

			mMatrix[0] = right.mX;
			mMatrix[1] = up.mX;
			mMatrix[2] = forward.mX;
			mMatrix[3] = pLookingPosition.mX;
			mMatrix[4] = right.mY;
			mMatrix[5] = up.mY;
			mMatrix[6] = forward.mY;
			mMatrix[7] = pLookingPosition.mY;
			mMatrix[8] = right.mZ;
			mMatrix[9] = up.mZ;
			mMatrix[10] = forward.mZ;
			mMatrix[11] = pLookingPosition.mZ;
		}

		void matrix_4::rotate_quaternions(float pAngle, float pRotateX, float pRotateY, float pRotateZ)
		{
			vector_4 quaternion;
			matrix_4 rotationMatrix;
			math_utilities mathMaster;
			float halfAngle = mathMaster.degrees_to_radians(pAngle / 2.0f);
			float sinHalfAngle = sin(halfAngle);
			quaternion.mX = sinHalfAngle * pRotateX;
			quaternion.mY = sinHalfAngle * pRotateY;
			quaternion.mZ = sinHalfAngle * pRotateZ;
			quaternion.mW = cos(halfAngle);
			rotationMatrix[0] = quaternion.mW;
			rotationMatrix[1] = quaternion.mX;
			rotationMatrix[2] = quaternion.mY;
			rotationMatrix[3] = quaternion.mZ;
			rotationMatrix[4] = -quaternion.mX;
			rotationMatrix[5] = quaternion.mW;
			rotationMatrix[6] = quaternion.mZ;
			rotationMatrix[7] = -quaternion.mY;
			rotationMatrix[8] = -quaternion.mY;
			rotationMatrix[9] = -quaternion.mZ;
			rotationMatrix[10] = quaternion.mW;
			rotationMatrix[11] = quaternion.mX;
			rotationMatrix[12] = -quaternion.mZ;
			rotationMatrix[13] = quaternion.mY;
			rotationMatrix[14] = -quaternion.mX;
			rotationMatrix[15] = quaternion.mW;
			*this = *this * rotationMatrix;
		}

		void matrix_4::scale(float pX, float pY, float pZ)
		{
			matrix_4 scaleMatrix;
			scaleMatrix.set_identity();
			scaleMatrix[0] = pX;
			scaleMatrix[5] = pY;
			scaleMatrix[10] = pZ;
			*this = *this * scaleMatrix;
		}
	}
}