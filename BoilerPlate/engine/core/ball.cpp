#include "ball.hpp"

namespace engine
{
	namespace core
	{
		ball::ball(){
			/* make ball, need formula for making a circle
			for (int i = 0; i < 800; i+=8)
			{
				mBallIndices[i] = cos(2 * 3.14 * i / 300.0);
				mBallIndices[i + 1] = sin(2 * 3.14*i / 300.0);
				mBallIndices[i + 2] = 1;
				mBallIndices[i + 4] = 1;
				mBallIndices[i + 5] = 1;
				mBallIndices[i + 6] = 1.0;
				mBallIndices[i + 7] = 0.0;
			}
			*/
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
