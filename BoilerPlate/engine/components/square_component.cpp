#include "engine\components\square_component.hpp"

namespace engine
{
	namespace component
	{
		square_component::square_component(std::string& pName, float pObjectWidth, float pObjectHeigth)
		{
			mName = pName;
			mObjectWidth = pObjectWidth;
			mObjectHeigth = pObjectHeigth;
		}

		float square_component::get_object_width()
		{
			return mObjectWidth;
		}

		float square_component::get_object_height()
		{
			return mObjectHeigth;
		}
	}
}