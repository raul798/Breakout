#include "engine\components\position_component.hpp"

namespace engine
{
	namespace component
	{
		position_component::position_component(std::string& pName)
		{
			mName = pName;
			mOrigin = math::vector_4();
		}
		
		position_component::position_component(std::string& pName, math::vector_4 pOrigin)
		{
			mName = pName;
			mOrigin = pOrigin;
		}

		math::vector_4* position_component::get_position()
		{
			return &mOrigin;
		}

		void position_component::set_position(math::vector_4 pNewPosition)
		{
			mOrigin = pNewPosition;
		}
	}
}