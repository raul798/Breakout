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
			vertex_component(std::string& pName, core::vertex pVertices[], int pIndices[]);
			core::vertex *get_vertex();
			int *get_indices();
		private:
			core::vertex mObjectVertices[36];
			int mObjectIndices[6];
		};
	}
}

#endif 