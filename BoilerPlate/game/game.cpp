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

		create_background();
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
		//mRenderManager.assign_textures("game/assets/background.png");
		mRenderManager.generate_buffers();

		level_generator::game_level firstLevel(mWidth, mHeight);
		firstLevel.load_level("game/levels/third_level.txt", 3.12, 0.9);

		this->mGameLevels.push_back(firstLevel);
	}

	void game::render()
	{
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
		mRenderManager.render
		(
			mBall.get_component("mVertex")->get_vertex(),
			mBall.get_component("mVertex")->get_indices(),
			mBall.get_component("mTextureIndex")->get_texture_index(),
			*mBall.get_component("mModel")->get_model_matrix()
		);
	}

	void game::update()
	{
		update_input_controller();
		mRenderManager.determine_polygon_mode();
		mGameLevels[0].update_screen_dimensions(mWidth, mHeight);
		detect_screen_collision();
		paddle_collision();
		//check_blocks_collision();
		//borrar
		movement();

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
			if (mPaddle.get_component("mOrigin")->get_position()->mX >= -1.6f)
			{
				mPaddle.get_component("mOrigin")->get_position()->mX -= *mPaddle.get_component("mPhysics")->get_movement_value();
			}
	
			mPaddle.get_component("mModel")->get_model_matrix()->set_identity();
			mPaddle.get_component("mModel")->get_model_matrix()->translate_vector(*mPaddle.get_component("mOrigin")->get_position());
			mPaddle.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
			mPaddle.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);

			if (mBall.get_AttchToPaddle() == true)
			{
				if (mPaddle.get_component("mOrigin")->get_position()->mX >= -1.6f)
				{
					mBall.get_component("mOrigin")->get_position()->mX = mPaddle.get_component("mOrigin")->get_position()->mX;
				}
				
				mBall.get_component("mModel")->get_model_matrix()->set_identity();
				mBall.get_component("mModel")->get_model_matrix()->translate_vector(*mBall.get_component("mOrigin")->get_position());
				mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
				mBall.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);
			}
		}

		if (mInputManager.get_d())
		{
			if (mPaddle.get_component("mOrigin")->get_position()->mX <= 1.6f)
			{
				mPaddle.get_component("mOrigin")->get_position()->mX += *mPaddle.get_component("mPhysics")->get_movement_value();
			}

			mPaddle.get_component("mModel")->get_model_matrix()->set_identity();		
			mPaddle.get_component("mModel")->get_model_matrix()->translate_vector(*mPaddle.get_component("mOrigin")->get_position());
			mPaddle.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
			mPaddle.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);

			if (mBall.get_AttchToPaddle() == true)
			{
				if (mPaddle.get_component("mOrigin")->get_position()->mX <= 1.6f)
				{
					mBall.get_component("mOrigin")->get_position()->mX = mPaddle.get_component("mOrigin")->get_position()->mX;
				}

				mBall.get_component("mModel")->get_model_matrix()->set_identity();
				mBall.get_component("mModel")->get_model_matrix()->translate_vector(*mBall.get_component("mOrigin")->get_position());
				mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
				mBall.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);
			}
		}

		if (mInputManager.get_space() && mInputCounter == 0)
		{
			
			if(mInputManager.get_d() == true && mBall.get_AttchToPaddle() == true)
			{
				*mBall.get_component("mPhysics")->get_angle() = 45.0f;
			}
			else if (mInputManager.get_a() == true && mBall.get_AttchToPaddle() == true)
			{
				*mBall.get_component("mPhysics")->get_angle() = 135.0f;
			}
			else if (mBall.get_AttchToPaddle() == true)
			{
				*mBall.get_component("mPhysics")->get_angle() = 90.0f;
			}

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
		if (mBall.get_AttchToPaddle() == false)
		{
			engine::math::math_utilities mathUtilities;
			engine::math::vector_4 *position;
			float *angle;
			angle = mBall.get_component("mPhysics")->get_angle();
			float diablo = mathUtilities.degrees_to_radians(*angle);

			position = mBall.get_component("mOrigin")->get_position();

			position->mY += (*mBall.get_component("mPhysics")->get_movement_value())*sinf(diablo);
			position->mX += (*mBall.get_component("mPhysics")->get_movement_value())*cosf(diablo);

			mBall.get_component("mModel")->get_model_matrix()->set_identity();
			mBall.get_component("mModel")->get_model_matrix()->translate_vector(*position);
			mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
			mBall.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);
		}
	}

	void game::create_background()
	{
		engine::core::vertex backgroundVertex[36];
		int backgroundIndices[6];
		backgroundVertex[0] = { 1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f };
		backgroundVertex[1] = { 1.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 0.0f };
		backgroundVertex[2] = { -1.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 1.0f };
		backgroundVertex[3] = { -1.0f, -1.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f };
		backgroundIndices[0] = 0;
		backgroundIndices[1] = 1;
		backgroundIndices[2] = 2;
		backgroundIndices[3] = 1;
		backgroundIndices[4] = 3;
		backgroundIndices[5] = 2;

		engine::component::model_matrix_component *backgroundModel = new engine::component::model_matrix_component("mModel");

		engine::component::texture_component *backgroundTexture = new engine::component::texture_component
		(std::string::basic_string("mTextureIndex"), 4);
		
		engine::component::position_component *backgroundPosition = new engine::component::position_component
		(std::string::basic_string("mOrigin"), engine::math::vector_4(0.0f, 0.0f, 0.0f, 0.0f));

		engine::component::vertex_component *backgroundVertices = new engine::component::vertex_component
		(std::string::basic_string("mVertex"), backgroundVertex, backgroundIndices);

		backgroundModel->get_model_matrix()->set_identity();

		mBackground.attach_component(backgroundModel);
		mBackground.attach_component(backgroundVertices);
		mBackground.attach_component(backgroundPosition);
		mBackground.attach_component(backgroundTexture);
	}

	void game::detect_screen_collision()
	{
		if (mBall.get_component("mOrigin")->get_position()->mX >= 1.6f)
		{
			if (*mBall.get_component("mPhysics")->get_angle() / 360.0f - (int)(*mBall.get_component("mPhysics")->get_angle() / 360) > 0.5f)
			{
				*mBall.get_component("mPhysics")->get_angle() -= 90.0f;
			}
			else
			{
				*mBall.get_component("mPhysics")->get_angle() += 90.0f;
			}
		}
		else if (mBall.get_component("mOrigin")->get_position()->mX <= -1.6f)
		{
			if (*mBall.get_component("mPhysics")->get_angle() / 360.0f - (int)(*mBall.get_component("mPhysics")->get_angle() / 360) > 0.5f)
			{
				*mBall.get_component("mPhysics")->get_angle() += 90.0f;
			}
			else
			{
				*mBall.get_component("mPhysics")->get_angle() -= 90.0f;
			}
		}

		if (mBall.get_component("mOrigin")->get_position()->mY >= 0.9f)
		{
			if (*mBall.get_component("mPhysics")->get_angle() / 360.0f - (int)(*mBall.get_component("mPhysics")->get_angle() / 360) > 0.25f)
			{
				*mBall.get_component("mPhysics")->get_angle() += 90.0f;
			}
			else
			{
				*mBall.get_component("mPhysics")->get_angle() -= 90.0f;
			}
		}
		else if (mBall.get_component("mOrigin")->get_position()->mY <= -0.9f)
		{
			mPlayerLives--;
			
			if (mPlayerLives >= 0)
			{
				respawn_ball();
			}
			else
			{
				//game over
			}
		}
	}

	void game::paddle_collision()
	{
		if (check_ball_collision(mPaddle))
		{
			if (*mBall.get_component("mPhysics")->get_angle() > 180.0f)
			{
				*mBall.get_component("mPhysics")->get_angle() += 90.0f;
			}
			else
			{
				*mBall.get_component("mPhysics")->get_angle() -= 90.0f;
			}
		}
	}

	bool game::check_ball_collision(engine::core::game_object pGameObject) // AABB 
	{
		if (mBall.get_AttchToPaddle() == false)
		{
			engine::math::math_utilities mathUtilities;

			engine::math::vector_2 center(mBall.get_component("mOrigin")->get_position()->mX , mBall.get_component("mOrigin")->get_position()->mY);
			engine::math::vector_2 aabb_half_extents
			(
			pGameObject.get_component("mDimension")->get_object_width() / 2, 
			pGameObject.get_component("mDimension")->get_object_height() / 2
			);

			engine::math::vector_2 aabb_center
			(
				pGameObject.get_component("mOrigin")->get_position()->mX,
				pGameObject.get_component("mOrigin")->get_position()->mY 
			);
			
			engine::math::vector_2 difference = center - aabb_center;

			float clampedX = mathUtilities.clamp(difference.mX, -1 * aabb_half_extents.mX, aabb_half_extents.mX);
			float clampedY = mathUtilities.clamp(difference.mY, -1 * aabb_half_extents.mY, aabb_half_extents.mY);

			engine::math::vector_2 clamped(clampedX, clampedY);
			engine::math::vector_2  closest = aabb_center + clamped;
			difference = closest - center;

			return engine::math::vector_2(difference).length() < engine::math::vector_2(mBall.get_component("mRadius")->get_radius()).length();
		}
		return false;
	}

	void game::check_blocks_collision()
	{
		std::vector<engine::core::block> blockCollision = mGameLevels[0].get_blocks();

		for (int i = 0; i < blockCollision.size(); i++)
		{
			if (check_ball_collision(blockCollision[i]))
			{
				if(blockCollision[i].get_is_solid() == true)
				{
					if (*mBall.get_component("mPhysics")->get_angle() > 180.0f)
					{
						*mBall.get_component("mPhysics")->get_angle() += 90.0f;
					}
					else
					{
						*mBall.get_component("mPhysics")->get_angle() -= 90.0f;
					}
				}
				else if(blockCollision[i].get_is_solid() == false)
				{
					mPlayerScore += blockCollision[i].get_score_value();

					mGameLevels[0].mBlocks.erase(mGameLevels[0].mBlocks.begin() + i);

					if (*mBall.get_component("mPhysics")->get_angle() > 180.0f)
					{
						*mBall.get_component("mPhysics")->get_angle() += 90.0f;
					}
					else
					{
						*mBall.get_component("mPhysics")->get_angle() -= 90.0f;
					}
				}
				break;
			}
		}
	}

	void game::respawn_ball()
	{
		mBall = engine::core::ball();
	}
}