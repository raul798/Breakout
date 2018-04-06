#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "../engine/components/model_matrix_component.hpp"
#include "../engine/components/position_component.hpp"
#include "../engine/components/texture_component.hpp"
#include "../engine/components/vertex_component.hpp"
#include "../engine/components/phisics_component.hpp"
#include "../engine/core/renderer.hpp"
#include "../engine/core/block.hpp"
#include "../engine/core/ball.hpp"
#include "../engine/utilities/input_manager.hpp"

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
		void update_screen_paremeter(int pWidth, int pHeight);
		void create_ball();
		void create_block();
		void movement();
		engine::utilities::input_manager mInputManager;

	private:
		engine::core::renderer mRenderManager;
		engine::core::ball mBall;
		engine::core::block mBlock;
		int mBlockCounter;
		int mInputCounter;
	};
}

#endif