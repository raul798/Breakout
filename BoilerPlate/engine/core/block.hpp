#pragma once
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/core/vertex.hpp"
#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/core/game_object.hpp"

namespace engine
{
	namespace core
	{
		class block:game_object
		{
		public:
			//constructor
			block();

			//getter
			vertex *get_block_vertices();
			int *get_block_indices();

		private:
			vertex mBlockVertices[32] = {
				// positions          // colors           // texture coords
				0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
				0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
				-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
				-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
			};

			int mBlockIndices[6] = { 0, 1, 2, 1, 3, 2 };
		};
	}
}

#endif
