#include "input_manager.hpp"

namespace engine
{
	namespace utilities
	{
		input_manager::input_manager()
		{
			mF = false;
		}

		//setters
		void input_manager::set_f(bool pF)
		{
			mF = pF;
		}

		//getters
		bool input_manager::get_f()
		{
			return mF;
		}
	}
}