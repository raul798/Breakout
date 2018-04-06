#include "engine\components\phisics_component.hpp"

namespace engine
{
	namespace component
	{
		phisics_component::phisics_component(std::string& pName, float pMovementValue)
		{
			mName = pName;
			mAngleDegree = 0.0f;
			mMovementValue = pMovementValue;
		}

		float *phisics_component::get_movement_value()
		{
			return &mMovementValue;
		}

		float *phisics_component::get_angle()
		{
			return &mAngleDegree;
		}
	}
}