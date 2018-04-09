#include "game.hpp"

namespace game
{
	game::game(){}

	game::game(int width, int height)
	{
		mInputCounter = 0;
		mBlockCounter = 0;
		
		mWidth = width;
		mHeight = height;
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
		mRenderManager.assign_textures("game/assets/block_solid.png");
		mRenderManager.assign_textures("game/assets/paddle.png");
		//convert from jpg to png
		//mRenderManager.assign_textures("game/assets/background.png");
		mRenderManager.generate_buffers();

		level_generator::game_level one;
		one.load_level("game/levels/first_level.txt", 2.0, 1.0);

		this->mGameLevels.push_back(one);
	}

	void game::render()
	{

		mRenderManager.render
		(
			mBall.get_component("mVertex")->get_vertex(),
			mBall.get_component("mVertex")->get_indices(),
			mBall.get_component("mTextureIndex")->get_texture_index(),
			*mBall.get_component("mModel")->get_model_matrix()
		);

		mRenderManager.render
		(
			mPaddle.get_component("mVertex")->get_vertex(),
			mPaddle.get_component("mVertex")->get_indices(),
			mPaddle.get_component("mTextureIndex")->get_texture_index(),
			*mPaddle.get_component("mModel")->get_model_matrix()
		);
		std::vector<engine::core::block> blockRenderer = mGameLevels[0].get_blocks();
		for (int i = 0; i < blockRenderer.size() ; i++)
		{
			mRenderManager.render(blockRenderer[i].get_component("mVertex")->get_vertex(),
				blockRenderer[i].get_component("mVertex")->get_indices(),
				blockRenderer[i].get_component("mTextureIndex")->get_texture_index(),
				*blockRenderer[i].get_component("mModel")->get_model_matrix());
				
		}
		
	}

	void game::update()
	{
		update_input_controller();
		mRenderManager.determine_polygon_mode();
		//borrar
		//movement();

		if (mBlockCounter == 0)
		{
			mBlockCounter++;
		}
	}

	void game::input_controller()
	{
		if (mInputManager.get_f() && mInputCounter == 0)
		{
			mRenderManager.switch_polygon_mode();

			reset_input_controller();
		}

		if (mInputManager.get_a()) 
		{
			mPaddle.get_component("mOrigin")->get_position()->mX -= *mPaddle.get_component("mPhisics")->get_movement_value();
		
			mPaddle.get_component("mModel")->get_model_matrix()->set_identity();
			mPaddle.get_component("mModel")->get_model_matrix()->translate_vector(*mPaddle.get_component("mOrigin")->get_position());
			mPaddle.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
			mPaddle.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);

			if (mBall.get_AttchToPaddle() == true)
			{
				mBall.get_component("mOrigin")->get_position()->mX -= *mPaddle.get_component("mPhisics")->get_movement_value();

				mBall.get_component("mModel")->get_model_matrix()->set_identity();
				mBall.get_component("mModel")->get_model_matrix()->translate_vector(*mBall.get_component("mOrigin")->get_position());
				mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
				mBall.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);
			}
		}

		if (mInputManager.get_d())
		{
			mPaddle.get_component("mOrigin")->get_position()->mX += *mPaddle.get_component("mPhisics")->get_movement_value();

			mPaddle.get_component("mModel")->get_model_matrix()->set_identity();		
			mPaddle.get_component("mModel")->get_model_matrix()->translate_vector(*mPaddle.get_component("mOrigin")->get_position());
			mPaddle.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
			mPaddle.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);

			if (mBall.get_AttchToPaddle() == true)
			{
				mBall.get_component("mOrigin")->get_position()->mX += *mPaddle.get_component("mPhisics")->get_movement_value();

				mBall.get_component("mModel")->get_model_matrix()->set_identity();
				mBall.get_component("mModel")->get_model_matrix()->translate_vector(*mBall.get_component("mOrigin")->get_position());
				mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
				mBall.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);
			}
		}

		if (mInputManager.get_space() && mInputCounter == 0)
		{
			mBall.change_AttchToPaddle();

			reset_input_controller();
		}
	}

	void game::reset_input_controller()
	{
		mInputCounter = 10;
	}

	void game::update_input_controller() 
	{
		input_controller();

		if (mInputCounter > 0) {

			mInputCounter--;
		}
	}

	void game::update_screen_paremeter(int pWidth, int pHeight)
	{
		mRenderManager.update_screen_parameters(pWidth, pHeight);
	}

	void game::movement()
	{
		engine::math::math_utilities mathUtilities;
		engine::math::vector_4 *position;
		float *angle;
		angle = mBall.get_component("mPhisics")->get_angle();
		float diablo = mathUtilities.degrees_to_radians(*angle);
		
		position = mBall.get_component("mOrigin")->get_position();

		position->mX += (*mBall.get_component("mPhisics")->get_movement_value())*-sinf(diablo);
		position->mY += (*mBall.get_component("mPhisics")->get_movement_value())*cosf(diablo);

		mBall.get_component("mModel")->get_model_matrix()->set_identity();
		mBall.get_component("mModel")->get_model_matrix()->translate_vector(*position);
		mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
		mBall.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);
	}
}