#include "engine\components\texture_component.hpp"

namespace engine
{
	namespace component
	{
		texture_component::texture_component(std::string& pName, int pTextureIndex)
		{
			mName = pName;
			mTextureIndex = pTextureIndex;
		}

		int texture_component::get_texture_index()
		{
			return mTextureIndex;
		}
	}
}