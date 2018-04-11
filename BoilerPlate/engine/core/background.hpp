#pragma once
#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "../core/vertex.hpp"
#include "../core/game_object.hpp"
#include "../components/model_matrix_component.hpp"
#include "../components/physics_component.hpp"
#include "../components/position_component.hpp"
#include "../components/texture_component.hpp"
#include "../components/vertex_component.hpp"

namespace engine
{
	namespace core
	{
		class background :public game_object
		{
		public:
			background();

		private:
			
		};
	}
}

#endif