#include "ball.hpp"

namespace engine
{
	namespace core
	{
		ball::ball(){
			// make ball, need formula for making a circle
			//for (int i = 0; i < 800; i+=8)
			//{
				/*
				//positions
				mBallIndices[i + 0] = cos(2 * 3.14 * i / 300.0);
				mBallIndices[i + 1] = sin(2 * 3.14*i / 300.0);
				mBallIndices[i + 2] = 0.0f;

				//colors
				mBallIndices[i + 4] = 1.0f;
				mBallIndices[i + 5] = 0.0f;
				mBallIndices[i + 6] = 0.0f;

				//textures
				mBallIndices[i + 7] = 1.0f;
				mBallIndices[i + 8] = 0.0f;
				*/
			//}
			

			mTextureIndex = 1;
		}

		vertex *ball::get_ball_vertices()
		{
			return mBallVertices;
		}

		int *ball::get_ball_indices()
		{
			return mBallIndices;
		}

		int ball::get_texture_index()
		{
			return mTextureIndex;
		}
	}
}
