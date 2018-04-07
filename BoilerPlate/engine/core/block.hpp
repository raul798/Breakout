#pragma once
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "../core/vertex.hpp"
#include "../core/game_object.hpp"
#include "../components/model_matrix_component.hpp"
#include "../components/phisics_component.hpp"
#include "../components/position_component.hpp"
#include "../components/texture_component.hpp"
#include "../components/vertex_component.hpp"

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

		private:
			bool mIsSolid;
			math::vector_2 mSize;
		};
	}
}

#endif