#pragma once
#ifndef BALL_HPP
#define BALL_HPP

#include "../core/vertex.hpp"
#include "../core/game_object.hpp"

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

