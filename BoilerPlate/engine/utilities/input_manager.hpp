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
			//F key
			void set_f(bool pF);
			bool get_f();

			//A key
			void set_a(bool pA);
			bool get_a();

			//D key
			void set_d(bool pD);
			bool get_d();

		private:
			bool mF;
			bool mA;
			bool mD;
		};
	}
}

#endif
