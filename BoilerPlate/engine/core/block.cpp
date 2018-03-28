#include "block.hpp"

namespace engine
{
	namespace core
	{
		block::block() {
			mTextureIndex = 0;
			mModel.translate_vector(math::vector_4(0.0f, 0.6f, 0.0f, 1.0f));
			mModel.rotate_z(0.0f);
		}

		vertex *block::get_block_vertices()
		{
			return mBlockVertices;
		}

		int *block::get_block_indices()
		{
			return mBlockIndices;
		}

		int block::get_texture_index()
		{
			return mTextureIndex;
		}
	}
}
