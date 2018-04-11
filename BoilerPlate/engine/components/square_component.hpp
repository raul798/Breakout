#pragma once
#ifndef SQUARE_COMPONENT_HPP
#define SQUARE_COMPONENT_HPP

#include "..\core\component.hpp"

namespace engine
{
	namespace component
	{
		class square_component : public core::component
		{
		public:
			square_component(std::string& pName, float pObjectWidth, float pObjectHeigth);
			float get_object_width();
			float get_object_height();

		private:
			float mObjectWidth;
			float mObjectHeigth;
		};
	}
}

#endif