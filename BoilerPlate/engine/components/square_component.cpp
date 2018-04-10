#include "engine\components\square_component.hpp"

namespace engine
{
	namespace component
	{
		square_component::square_component(std::string& pName, float pObjectWidth, float pObejctHeigth)
		{
			mName = pName;
			mObjectWidth = pObjectWidth;
			mObejctHeigth = pObejctHeigth;
		}
	}
}