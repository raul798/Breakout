#pragma once
#ifndef POSITION_COMPONENT_HPP
#define POSITION_COMPONENT_HPP

#include "..\core\component.hpp"

namespace engine
{
	namespace component
	{
		class position_component : public core::component
		{
		public:
			position_component(std::string& pName);
			position_component(std::string& pName, math::vector_4 pOrigin, float pAngle);
			//override
			math::vector_4* get_position();
			float* get_angle();
		private:
			math::vector_4 mOrigin;
			float mAngleDegree;
			
		};
	}
}

#endif