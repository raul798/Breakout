#include "ball.hpp"

namespace engine
{
	namespace core
	{
		ball::ball()
		{
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
