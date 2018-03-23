#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/math/Matrix_4.hpp"
#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/core/renderer.hpp"
#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/core/block.hpp"
#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/core/ball.hpp"
#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/utilities/input_manager.hpp"

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
		void render();
		void update();
		void input_controller();
		void reset_input_controller();
		void update_input_controller();
		
		engine::utilities::input_manager mInputManager;

	private:
		engine::core::renderer mRenderManager;
		engine::core::ball mBall;
		engine::core::block mBlock;
		int mInputCounter;
	};
}

#endif