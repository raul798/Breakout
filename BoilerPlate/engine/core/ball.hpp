#pragma once
#ifndef BALL_HPP
#define BALL_HPP

#include "../core/vertex.hpp"
#include "../core/game_object.hpp"
#include "../components/model_matrix_component.hpp"
#include "../components/physics_component.hpp"
#include "../components/position_component.hpp"
#include "../components/texture_component.hpp"
#include "../components/vertex_component.hpp"
#include "../components/round_component.hpp"

namespace engine
{
	namespace core
	{
		class ball:public game_object
		{
		public:
			//constructor
			ball();

			//functions
			bool get_AttchToPaddle();
			void change_AttchToPaddle();

		private:
			bool mIsAttachToPaddle;
		};
	}
}

#endif

