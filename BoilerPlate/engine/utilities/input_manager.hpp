#pragma once
#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

namespace engine
{
	namespace utilities
	{
		class input_manager 
		{

		public:
			//costructor
			input_manager();

			//getters and setters
			void set_f(bool pF);
			bool get_f();

		private:
			bool mF;
		};
	}
}

#endif
