#pragma once
#ifndef PADDLE_HPP
#define PADDLE_HPP

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
		class paddle :public game_object
		{
		public:
			paddle();

		private:
		};
	}
}

#endif