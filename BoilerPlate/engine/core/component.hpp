#pragma once
#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

#include "IUpdate.hpp"

namespace engine
{
	namespace core
	{
		class game_object;
		class component : IUpdate
		{
		public:
			//public functions
			explicit component();
			explicit component(const std::string& pName);
			~component();
			void update(double pDeltaTime) override;

			//getters and setters
			void set_owner(game_object* pOwner) { mOwner = pOwner; }
			game_object* get_owner() const { return mOwner; }
			std::string get_name() const { return mName; }

		protected:
			//members
			game_object *mOwner;
			std::string	mName;
		};
	}
}

#endif 