#pragma once
#ifndef BALL_HPP
#define BALL_HPP

#include "../core/vertex.hpp"
#include "../core/game_object.hpp"

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
			vertex mBallVertices[4] = {
				// positions         // colors           // texture coords
				{0.03f, 0.03f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f},   // top right
				{0.03f, -0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 0.0f},   // bottom right
				{-0.03f, 0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 1.0f},   // top left
				{-0.03f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f}    // bottom left     
			};

			int mBallIndices[7] = { 0, 1, 2, 1, 3, 2, 0 };
			int mTextureIndex;
		};
	}
}

#endif

