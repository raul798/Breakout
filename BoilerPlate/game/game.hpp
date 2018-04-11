#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "../engine/components/model_matrix_component.hpp"
#include "../engine/components/physics_component.hpp"
#include "../engine/components/position_component.hpp"
#include "../engine/components/texture_component.hpp"
#include "../engine/components/vertex_component.hpp"
#include "../engine/core/renderer.hpp"
#include "../engine/core/ball.hpp"
#include "../engine/core/block.hpp"
#include "../engine/core/paddle.hpp"
#include "../engine/utilities/input_manager.hpp"
#include "../game/level_generator/game_level.hpp"

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
		void movement();
		void create_background();
		void detect_screen_collision();
		void paddle_collision();
		bool check_ball_collision(engine::core::game_object pGameObject);
		engine::utilities::input_manager mInputManager;

	private:
		engine::core::renderer mRenderManager;
		engine::core::ball mBall;
		engine::core::paddle mPaddle;
		engine::core::game_object mBackground;
		std::vector<level_generator::game_level> mGameLevels;
		int mBlockCounter;
		int mInputCounter;
		int mWidth;
		int mHeight;
	};
}

#endif