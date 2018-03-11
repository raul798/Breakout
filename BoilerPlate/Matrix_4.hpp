#pragma once

namespace engine
{
	class Matrix_4
	{
	public:
		Matrix_4();
		Matrix_4(float, float, float, float, float, float, float, float, 
			float, float, float, float, float, float, float, float);
		Matrix_4(float pArray[]);
	private:
		float mMatrix[4][4];
	};
}