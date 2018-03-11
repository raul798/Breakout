#pragma once
#ifndef MATRIX_4_HPP
#define MATRIX_4_HPP


namespace engine
{
	class matrix_4
	{
	public:
		//constructors
		matrix_4();
		matrix_4(float pArray[15]);
		matrix_4(float pValue11, float pValue21, float pValue31, float pValue41,
				 float pValue12, float pValue22, float pValue32, float pValue42,
				 float pValue13, float pValue23, float pValue33, float pValue43,
				 float pValue14, float pValue24, float pValue34, float pValue44);
		
	private:
		float mMatrix[4][4];
	};
}

#endif