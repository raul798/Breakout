#include "ball.hpp"

namespace engine
{
	namespace core
	{
		ball::ball(){}

		vertex *ball::get_ball_vertices()
		{
			return mBallVertices;
		}

		int *ball::get_ball_indices()
		{
			return mBallIndices;
		}
	}
}
