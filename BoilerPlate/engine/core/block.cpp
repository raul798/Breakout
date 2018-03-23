#include "block.hpp"

namespace engine
{
	namespace core
	{
		block::block() {}

		vertex *block::get_block_vertices()
		{
			return mBlockVertices;
		}

		int *block::get_block_indices()
		{
			return mBlockIndices;
		}
	}
}
