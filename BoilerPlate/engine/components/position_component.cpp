#include "engine\components\position_component.hpp"

namespace engine
{
	namespace component
	{
		position_component::position_component(std::string& pName)
		{
			mName = pName;
			mOrigin = math::vector_4();
			mAngleDegree = 0.0f;
		}
		
		position_component::position_component(std::string& pName, math::vector_4 pOrigin, float pAngle)
		{
			mName = pName;
			mOrigin = pOrigin;
			mAngleDegree = pAngle;
		}

		math::vector_4* position_component::get_position()
		{
			return &mOrigin;
		}

		float* position_component::get_angle()
		{
			return &mAngleDegree;
		}
	}
}