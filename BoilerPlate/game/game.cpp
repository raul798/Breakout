#include "game.hpp"

namespace game
{
	game::game()
	{
		//engine::component::model_matrix_component ballModel = engine::component::model_matrix_component("mModel");
		//mBall.attach_component(&ballModel);
		mInputCounter = 0;
	}

	game::~game()
	{
		mRenderManager.~renderer();
	}

	void game::execute()
	{
		mRenderManager.assign_program_id();
		mRenderManager.assign_textures("game/assets/block.png");
		mRenderManager.assign_textures("game/assets/ball.png");
		mRenderManager.generate_buffers();
	}

	void game::render()
	{
		mRenderManager.render(mBlock.get_block_vertices(), mBlock.get_block_indices(), mBlock.get_texture_index(), mBlock.get_model_matrix());
		mRenderManager.render(mBall.get_ball_vertices(), mBall.get_ball_indices(), mBall.get_texture_index(), mBall.get_model_matrix());
	}

	void game::update()
	{
		update_input_controller();
		mRenderManager.determine_polygon_mode();
	}

	void game::input_controller()
	{
		if (mInputManager.get_f() && mInputCounter == 0) {

			mRenderManager.switch_polygon_mode();

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

	void game::update_screen_paremeter(int pWidth, int pHeight)
	{
		mRenderManager.update_screen_parameters(pWidth, pHeight);
	}
}