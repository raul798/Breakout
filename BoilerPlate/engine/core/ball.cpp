#include "ball.hpp"

namespace engine
{
	namespace core
	{
		ball::ball()
		{
			mIsAttachToPaddle = true;

			engine::core::vertex ballVertex[36];
			int ballIndices[6];
			ballVertex[0] = { 0.03f, 0.03f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,  1.0f, 1.0f };
			ballVertex[1] = { 0.03f, -0.03f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  1.0f, 0.0f };
			ballVertex[2] = { -0.03f, 0.03f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 1.0f };
			ballVertex[3] = { -0.03f, -0.03f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f };
			ballIndices[0] = 0;
			ballIndices[1] = 1;
			ballIndices[2] = 2;
			ballIndices[3] = 1;
			ballIndices[4] = 3;
			ballIndices[5] = 2;

			engine::component::model_matrix_component *ballModel = new engine::component::model_matrix_component("mModel");

			engine::component::position_component *ballPosition = new engine::component::position_component(std::string::basic_string
			("mOrigin"), engine::math::vector_4(0.0f, -0.9f, 0.0f, 0.0f) + engine::math::vector_4(0.0f, 0.077f, 0.0f, 0.0f));

			engine::component::texture_component *ballTexture = new engine::component::texture_component(std::string::basic_string("mTextureIndex"), 1);

			engine::component::phisics_component *ballPhisics = new engine::component::phisics_component
			(std::string::basic_string("mPhisics"), 0.001f);

			engine::component::vertex_component *ballVertices = new engine::component::vertex_component
			(std::string::basic_string("mVertex"), ballVertex, ballIndices);

			ballModel->get_model_matrix()->translate_vector(*ballPosition->get_position());
			ballModel->get_model_matrix()->rotate_z(0.0f);
			ballModel->get_model_matrix()->scale(1.0, 1.0, 1.0);

			attach_component(ballModel);
			attach_component(ballVertices);
			attach_component(ballPosition);
			attach_component(ballPhisics);
			attach_component(ballTexture);
		}

		bool ball::get_AttchToPaddle()
		{
			return mIsAttachToPaddle;
		}

		void ball::change_AttchToPaddle()
		{
			if (mIsAttachToPaddle == true)
			{
				mIsAttachToPaddle = false;
			}
		}
	}
}
