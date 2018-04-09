#include"engine\components\vertex_component.hpp"

namespace engine
{
	namespace component
	{
		vertex_component::vertex_component(std::string& pName, core::vertex pVertices[], int pIndices[])
		{
			mName = pName;

			for (int i = 0; i < 36; i++)
			{
				mObjectVertices[i] = pVertices[i];
			}

			for (int i = 0; i < 6; i++)
			{
				mObjectIndices[i] = pIndices[i];
			}
			
			
		}
		
		int *vertex_component::get_indices()
		{
			return mObjectIndices;
		}

		core::vertex *vertex_component::get_vertex()
		{
			return mObjectVertices;
		}
	}
}