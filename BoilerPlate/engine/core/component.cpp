#include "component.hpp"

namespace engine
{
	namespace core
	{
		component::component()
		{

		}
		component::component(const std::string& pName)
		{
			mName = pName;
		}

		component::~component()
		{
			mOwner = nullptr;
		}

		void component::update(double pDeltaTime)
		{
			IUpdate::update(pDeltaTime);
		}
	}
}