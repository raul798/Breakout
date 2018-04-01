#pragma once
#ifndef TEXTURE_COMPONENT_HPP_
#define TEXTURE_COMPONENT_HPP_

#include <string>

#include "../core/component.hpp"

namespace engine
{
	namespace component
	{
		struct texture_component : public core::component
		{
		public:
			texture_component(std::string& pName, std::string& pTexturePath);
			std::string get_texture_path();
		private:
			std::string mTexturePath;
		
		};
	}
}

#endif

