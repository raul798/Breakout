#include "block.hpp"

namespace engine
{
	namespace core
	{
		block::block(){}

		block::block(math::vector_2 pSize, bool pIsSolid, math::vector_4 color)
		{
			engine::core::vertex blockVertex[36];
			int blockIndices[6];
			blockVertex[0] = { 0.05f, 0.05f, 0.0f,    color.mX, color.mY, color.mZ, color.mW,  1.0f, 1.0f };
			blockVertex[1] = { 0.05f, -0.05f, 0.0f,   color.mX, color.mY, color.mZ, color.mW,  1.0f, 0.0f };
			blockVertex[2] = { -0.05f, 0.05f, 0.0f,   color.mX, color.mY, color.mZ, color.mW,  0.0f, 1.0f };
			blockVertex[3] = { -0.05f, -0.05f, 0.0f,  color.mX, color.mY, color.mZ, color.mW,  0.0f, 0.0f };
			blockIndices[0] = 0;
			blockIndices[1] = 1;
			blockIndices[2] = 2;
			blockIndices[3] = 1;
			blockIndices[4] = 3;
			blockIndices[5] = 2;

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

			engine::component::square_component *blockDimension = new engine::component::square_component
			(std::string::basic_string("mDimension"), 0.05f, 0.05f);

			attach_component(blockModel);
			attach_component(blockVertices);
			attach_component(blockPosition);
			attach_component(blockTexture);
			attach_component(blockDimension);

			mSize = pSize;
			mIsSolid = pIsSolid;
		}

		bool block::get_is_solid()
		{
			return mIsSolid;
		}
	}
}
