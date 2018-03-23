#pragma once
#ifndef _IRENDER_HPP_
#define _IRENDER_HPP_

namespace engine
{
	namespace core
	{
		class IRender
		{
		public:
			virtual ~IRender() = default;
			
			//public functions
			void virtual render() = 0;
		};
	}
}

#endif 