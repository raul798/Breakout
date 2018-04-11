#pragma once
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "../core/vertex.hpp"
#include "../core/game_object.hpp"
#include "../components/model_matrix_component.hpp"
#include "../components/physics_component.hpp"
#include "../components/position_component.hpp"
#include "../components/texture_component.hpp"
#include "../components/vertex_component.hpp"
#include "../components/square_component.hpp"

namespace engine
{
	namespace core
	{
		class block :public game_object
		{
		public:
			block(math::vector_2 pSize, bool pIsSolid, math::vector_4 color);
			block();

			bool get_is_solid();
			int get_score_value();

		private:
<<<<<<< HEAD
			vertex mBlockVertices[4] = {
				// positions         // colors           // texture coords
				{ 0.06f, 0.06f, 0.0f,    1.0f, 0.0f, 0.0f, 1.0f,   1.0f, 1.0f },   // top right
				{ 0.06f, -0.06f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,   1.0f, 0.0f },   // bottom right
				{ -0.06f, 0.06f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,   0.0f, 1.0f },   // top left
				{ -0.06f, -0.06f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,   0.0f, 0.0f }    // bottom left    
			};

			int mBlockIndices[7] = { 0, 1, 2, 1, 3, 2, 0 };
			int mTextureIndex;
=======
			bool mIsSolid;
			math::vector_2 mSize;
			int mScoreValue = 10;
>>>>>>> feature/lvl_generator
		};
	}
}

#endif