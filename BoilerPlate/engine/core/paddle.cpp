#include "paddle.hpp"

namespace engine
{
	namespace core
	{
		paddle::paddle() 
		{
			engine::core::vertex paddleVertex[36];
			int paddleIndices[6];
			paddleVertex[0] = { 0.2f, 0.035f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f };
			paddleVertex[1] = { 0.2f, -0.035f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 0.0f };
			paddleVertex[2] = { -0.2f, 0.035f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 1.0f };
			paddleVertex[3] = { -0.2f, -0.035f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f };
			paddleIndices[0] = 0;
			paddleIndices[1] = 1;
			paddleIndices[2] = 2;
			paddleIndices[3] = 1;
			paddleIndices[4] = 3;
			paddleIndices[5] = 2;

			engine::component::model_matrix_component *paddleModel = new engine::component::model_matrix_component("mModel");

			engine::component::position_component *paddlePosition = new engine::component::position_component
			(std::string::basic_string("mOrigin"), engine::math::vector_4(0.0f, -0.9f, 0.0f, 0.0f));

			engine::component::texture_component *paddleTexture = new engine::component::texture_component(std::string::basic_string("mTextureIndex"), 3);

			engine::component::phisics_component *paddlePhisics = new engine::component::phisics_component
			(std::string::basic_string("mPhysics"), 0.02f);

			engine::component::vertex_component *paddleVertices = new engine::component::vertex_component
			(std::string::basic_string("mVertex"), paddleVertex, paddleIndices);

			paddleModel->get_model_matrix()->translate_vector(*paddlePosition->get_position());
			paddleModel->get_model_matrix()->rotate_z(0.0f);
			paddleModel->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);

			attach_component(paddleModel);
			attach_component(paddleVertices);
			attach_component(paddlePosition);
			attach_component(paddlePhisics);
			attach_component(paddleTexture);
		}
	}
}
