#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/math/Matrix_4.hpp"
#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/core/renderer.hpp"

namespace game
{
	class game
	{
	public:
		//constructors
		game();
		~game();

		//functions
		void execute();

		
	private:
		engine::core::renderer renderManager;
	};
}

#endif