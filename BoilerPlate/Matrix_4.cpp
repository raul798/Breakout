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
	matrix_4::matrix_4(float pValue11, float pValue21, float pValue31, float pValue41,
					   float pValue12, float pValue22, float pValue32, float pValue42,
					   float pValue13, float pValue23, float pValue33, float pValue43,
					   float pValue14, float pValue24, float pValue34, float pValue44)
	{
		//matrix[row][column]
		//first column
		mMatrix[0][0] = pValue11;
		mMatrix[1][0] = pValue21;
		mMatrix[2][0] = pValue31;
		mMatrix[3][0] = pValue41;

		//second column
		mMatrix[0][1] = pValue12;
		mMatrix[1][1] = pValue22;
		mMatrix[2][1] = pValue32;
		mMatrix[3][1] = pValue42;

		//third column
		mMatrix[0][2] = pValue13;
		mMatrix[1][2] = pValue23;
		mMatrix[2][2] = pValue33;
		mMatrix[3][2] = pValue43;

		//fourth column
		mMatrix[0][3] = pValue14;
		mMatrix[1][3] = pValue24;
		mMatrix[2][3] = pValue34;
		mMatrix[3][3] = pValue44;
	}
}
