#pragma once
#ifndef VERTEX_COMPONENT_HPP_
#define VERTEX_COMPONENT_HPP_

#include <string>

#include "../core/component.hpp"

namespace engine
{
	namespace component
	{
		struct texture_component : core::component
		{
			std::string mTexturePath;
		};
	}
}

#endif

