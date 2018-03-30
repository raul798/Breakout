#pragma once
#ifndef VERTEX_COMPONENT_HPP_
#define VERTEX_COMPONENT_HPP_

#include "../core/component.hpp"
#include "../core/vertex.hpp"

namespace engine
{
	namespace component
	{
		const int NUMBER_OF_INDICES = 7;
		const int NUMBER_OF_VERTICES = 4;

		struct vertex_component : core::component
		{
			core::vertex mObjectVertices[NUMBER_OF_VERTICES];
			int mObjectIndices[NUMBER_OF_INDICES];
		};
	}
}

#endif 