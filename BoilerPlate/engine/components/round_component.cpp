#include "engine\components\round_component.hpp"

namespace engine
{
	namespace component
	{
		round_component::round_component(std::string& pName, float pRadius)
		{
			mName = pName;
			mRadius = pRadius;
		}
	}
}