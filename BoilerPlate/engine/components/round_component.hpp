#pragma once
#ifndef ROUND_COMPONENT_HPP
#define ROUND_COMPONENT_HPP

#include "..\core\component.hpp"

namespace engine
{
	namespace component
	{
		class round_component : public core::component
		{
		public:
			round_component(std::string& pName, float pRadius);

		private:
			float mRadius;
		};
	}
}

#endif