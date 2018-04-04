#include"engine\components\vertex_component.hpp"

namespace engine
{
	namespace component
	{
		vertex_component::vertex_component(std::string& pName, std::vector<core::vertex> pVertices, std::vector<int> pIndices)
		{
			mName = pName;
			mObjectVertices = pVertices;
			mObjectIndices = pIndices;
		}
		
		std::vector<int> vertex_component::get_indices()
		{
			return mObjectIndices;
		}

		std::vector<core::vertex> vertex_component::get_vertex()
		{
			return mObjectVertices;
		}
	}
}