#include "input_manager.hpp"

namespace engine
{
	namespace utilities
	{
		input_manager::input_manager()
		{
			mF = false;
			mA = false;
			mD = false;
			mSpace = false;
		}

		//setters
		void input_manager::set_f(bool pF)
		{
			mF = pF;
		}

		void input_manager::set_a(bool pA)
		{
			mA = pA;
		}

		void input_manager::set_d(bool pD)
		{
			mD = pD;
		}

		void input_manager::set_space(bool pSpace)
		{
			mSpace = pSpace;
		}

		//getters
		bool input_manager::get_f()
		{
			return mF;
		}

		bool input_manager::get_a()
		{
			return mA;
		}

		bool input_manager::get_d()
		{
			return mD;
		}


		bool input_manager::get_space()
		{
			return mSpace;
		}
	}
}