#pragma once
#ifndef VERTEX_COMPONENT_HPP_
#define VERTEX_COMPONENT_HPP_

#include <vector>

#include "../core/component.hpp"
#include "../core/vertex.hpp"

namespace engine
{
	namespace component
	{
		const int NUMBER_OF_INDICES = 7;
		const int NUMBER_OF_VERTICES = 4;

		struct vertex_component : public core::component
		{
			
			std::vector<core::vertex> mObjectVertices;
			std::vector<int> mObjectIndices;

		public:
			vertex_component(std::string& pName, std::vector<core::vertex> pVertices, std::vector<int> pIndices);
		};
	}
}

#endif 