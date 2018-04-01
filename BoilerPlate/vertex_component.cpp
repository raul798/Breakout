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
	}
}