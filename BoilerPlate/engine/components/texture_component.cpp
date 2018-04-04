#include "engine\components\texture_component.hpp"

namespace engine
{
	namespace component
	{
		texture_component::texture_component(std::string& pName, std::string& pTexturePath)
		{
			mName = pName;
			mTexturePath = pTexturePath;
		}
		std::string texture_component::get_texture_path()
		{
			return mTexturePath;
		}
	}
}