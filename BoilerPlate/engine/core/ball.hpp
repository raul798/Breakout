#pragma once
#ifndef BALL_HPP
#define BALL_HPP

#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/core/vertex.hpp"
#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/core/game_object.hpp"

namespace engine
{
	namespace core
	{
		class ball:game_object
		{
		public:
			//constructor
			ball();

			//getter
			vertex *get_ball_vertices();
			int *get_ball_indices();
			int get_texture_index();

		private:
			vertex mBallVertices[32] = {
				// positions          // colors           // texture coords
				0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
				0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
				-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
				-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
			};

			int mBallIndices[6] = { 0, 1, 2, 0, 3, 2 };
			int mTextureIndex;
		};
	}
}

#endif
