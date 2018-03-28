#include "ball.hpp"

namespace engine
{
	namespace core
	{
		ball::ball()
		{
			mTextureIndex = 1;
			mModel.translate_vector(math::vector_4(0.0f, 0.0f, 0.0f, 1.0f));
			mModel.rotate_z(0.0f);
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
