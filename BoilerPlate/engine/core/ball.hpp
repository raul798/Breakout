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
			void set_attchToPaddle(bool pStatus);
		private:
<<<<<<< HEAD
			vertex mBallVertices[4] = {
				// positions         // colors           // texture coords
				{0.03f, 0.03f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f},   // top right
				{0.03f, -0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 0.0f},   // bottom right
				{-0.03f, 0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 1.0f},   // top left
				{-0.03f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f}    // bottom left     
			};

			int mBallIndices[7] = { 0, 1, 2, 1, 3, 2, 0 };
			int mTextureIndex;
=======
			bool mIsAttachToPaddle;
>>>>>>> feature/lvl_generator
		};
	}
}

#endif

