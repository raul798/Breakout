#include "block.hpp"

namespace engine
{
	namespace core
	{
		block::block(){}

		block::block(math::vector_2 pSize, bool pIsSolid, math::vector_4 color)
		{
			std::vector<engine::core::vertex> blockVertex;
			std::vector<int> blockIndices;
			blockVertex.push_back({ 0.06f, 0.06f, 0.0f,    color.mX, color.mY, color.mZ, color.mW,  1.0f, 1.0f });
			blockVertex.push_back({ 0.06f, -0.06f, 0.0f,   color.mX, color.mY, color.mZ, color.mW,  1.0f, 0.0f });
			blockVertex.push_back({ -0.06f, 0.06f, 0.0f,   color.mX, color.mY, color.mZ, color.mW,  0.0f, 1.0f });
			blockVertex.push_back({ -0.06f, -0.06f, 0.0f,  color.mX, color.mY, color.mZ, color.mW,  0.0f, 0.0f });
			blockIndices.push_back(0);
			blockIndices.push_back(1);
			blockIndices.push_back(2);
			blockIndices.push_back(1);
			blockIndices.push_back(3);
			blockIndices.push_back(2);
			blockIndices.push_back(0);

			engine::component::model_matrix_component *blockModel = new engine::component::model_matrix_component("mModel");

			engine::component::texture_component *blockTexture;

			if (pIsSolid == true) 
			{
				blockTexture = new engine::component::texture_component(std::string::basic_string("mTextureIndex"), 2);
			}
			else
			{
				blockTexture = new engine::component::texture_component(std::string::basic_string("mTextureIndex"), 0);
			}

			engine::component::position_component *blockPosition = new engine::component::position_component
			(std::string::basic_string("mOrigin"), engine::math::vector_4(0.0f, 0.6f, 0.0f, 0.0f));

			engine::component::vertex_component *blockVertices = new engine::component::vertex_component
			(std::string::basic_string("mVertex"), blockVertex, blockIndices);

			//move this
			//blockModel->get_model_matrix()->translate_vector(*blockPosition->get_position());
			//blockModel->get_model_matrix()->rotate_z(0.0f);

			attach_component(blockModel);
			attach_component(blockVertices);
			attach_component(blockPosition);
			attach_component(blockTexture);

			mSize = pSize;
			mIsSolid = pIsSolid;
		}

		bool block::get_is_solid()
		{
			return mIsSolid;
		}
	}
}
