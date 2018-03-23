#include "game.hpp"

namespace game
{
	game::game()
	{
		mInputCounter = 0;
	}

	game::~game() 
	{
		renderManager.~renderer();
	}

	void game::execute()
	{
		renderManager.assign_program_id();
		renderManager.assign_textures("game/assets/block.png");
		renderManager.assign_textures("game/assets/ball.png");
		renderManager.generate_buffers();
	}

	void game::render()
	{
		renderManager.render(ball.get_ball_vertices(), ball.get_ball_indices(), ball.get_texture_index());
	}

	void game::update()
	{
		update_input_controller();
		renderManager.determine_polygon_mode();
	}

	void game::input_controller() 
	{
		if (mInputManager.get_f() && mInputCounter == 0) {

			renderManager.switch_polygon_mode();

			reset_input_controller();
		}
	}

	void game::reset_input_controller()
	{
		mInputCounter = 10;
	}

	void game::update_input_controller() {

		input_controller();

		if (mInputCounter > 0) {

			mInputCounter--;
		}
	}
}