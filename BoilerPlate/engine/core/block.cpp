#include "block.hpp"

namespace engine
{
	namespace core
	{
		block::block() {
			mTextureIndex = 1;
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
