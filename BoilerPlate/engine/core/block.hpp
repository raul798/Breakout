#pragma once
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "../core/vertex.hpp"
#include "../core/game_object.hpp"

namespace engine
{
	namespace core
	{
		class block :public game_object
		{
		public:
			block();
		};
	}
}

#endif