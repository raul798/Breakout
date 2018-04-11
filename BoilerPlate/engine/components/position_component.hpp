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
			position_component(std::string& pName, math::vector_4 pOrigin);
			//override
			math::vector_4* get_position();
			void set_position(math::vector_4 pNewPosition);

		private:
			math::vector_4 mOrigin;
		};
	}
}

#endif