#pragma once
#ifndef PHISICS_COMPONENT_HPP
#define PHISICS_COMPONENT_HPP

#include "..\core\component.hpp"



namespace engine
{
	namespace component
	{
		class phisics_component : public core::component
		{
		public:
			phisics_component(std::string& pName, math::vector_4 pVelocity, float pMovementValue);
			float *get_movement_value();
			float *get_angle();
	
		private:
			float mMovementValue;
			float mAngleDegree;
			math::vector_4 velocity;
		};
	}
}

#endif