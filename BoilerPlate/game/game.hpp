#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "../engine/components/model_matrix_component.hpp"
#include "../engine/components/phisics_component.hpp"
#include "../engine/components/position_component.hpp"
#include "../engine/components/texture_component.hpp"
#include "../engine/components/vertex_component.hpp"
#include "../engine/core/renderer.hpp"
#include "../engine/core/ball.hpp"
#include "../engine/core/block.hpp"
#include "../engine/core/paddle.hpp"
#include "../engine/utilities/input_manager.hpp"
#include "../game/game levels/game_level.hpp"

namespace game
{
	class game
	{
	public:
		//constructors
		game(int width, int height);
		~game();
		game();

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
		void create_paddle();
		void movement();
		engine::utilities::input_manager mInputManager;

	private:
		engine::core::renderer mRenderManager;
		engine::core::ball mBall;
		engine::core::block mBlock = engine::core::block(engine::math::vector_2(1.0f, 1.0f), false, engine::math::vector_4(1.0f, 1.0f, 1.0f, 1.0f));
		engine::core::paddle mPaddle;
		std::vector<level::game_level> mGameLevels;
		int mBlockCounter;
		int mInputCounter;
		int mWidth;
		int mHeight;
	};
}

#endif