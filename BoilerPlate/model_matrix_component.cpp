#include "engine\components\model_matrix_component.hpp"

namespace engine
{
	namespace component
	{
		model_matrix_component::model_matrix_component(const std::string& pName)
		{
			mName = pName;
			mModelMatrix = math::matrix_4();
		}
	}
}