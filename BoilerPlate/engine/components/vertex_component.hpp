#pragma once
#ifndef VERTEX_COMPONENT_HPP_
#define VERTEX_COMPONENT_HPP_



#include "../core/component.hpp"

namespace engine
{
	namespace component
	{
		const int NUMBER_OF_INDICES = 7;
		const int NUMBER_OF_VERTICES = 4;

		struct vertex_component : public core::component
		{
		public:
			vertex_component(std::string& pName, std::vector<core::vertex> pVertices, std::vector<int> pIndices);
			std::vector<core::vertex> get_vertex();
			std::vector<int> get_indices();
		private:
			std::vector<core::vertex> mObjectVertices;
			std::vector<int> mObjectIndices;
		};
	}
}

#endif 