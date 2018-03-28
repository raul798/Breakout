#pragma once
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "../core/vertex.hpp"
#include "../core/game_object.hpp"

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
			int get_texture_index();

		private:
			vertex mBlockVertices[4] = {
				// positions         // colors           // texture coords
				{ 0.2f, 0.2f, 0.0f,    1.0f, 0.0f, 0.0f, 1.0f,   1.0f, 1.0f },   // top right
				{ 0.2f, -0.2f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,   1.0f, 0.0f },   // bottom right
				{ -0.2f, 0.2f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,   0.0f, 1.0f },   // top left
				{ -0.2f, -0.2f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,   0.0f, 0.0f }    // bottom left    
			};

			int mBlockIndices[7] = { 0, 1, 2, 1, 3, 2, 0 };
			int mTextureIndex;
		};
	}
}

#endif
