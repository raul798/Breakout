#include "game.hpp"
#include <irrKlang.h>

namespace game
{
	irrklang::ISoundEngine *SoundEngine = irrklang::createIrrKlangDevice();
	game::game(){}

	game::game(int width, int height)
	{
		mInputCounter = 0;
		mBlockCounter = 0;
		mLvl = 0;
		mWidth = width;
		mHeight = height;

		mPlayerLives = 3;
		//create_lives();

		mPlayerRemainingLives = std::vector<engine::core::game_object>(mPlayerLives);
		
		for (int i = 0; i < 3; i++)
		{
			engine::core::vertex liveVertex[36];
			int liveIndices[6];
			liveVertex[0] = { 0.03f, 0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f };
			liveVertex[1] = { 0.03f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 0.0f };
			liveVertex[2] = { -0.03f, 0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 1.0f };
			liveVertex[3] = { -0.03f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f };
			liveIndices[0] = 0;
			liveIndices[1] = 1;
			liveIndices[2] = 2;
			liveIndices[3] = 1;
			liveIndices[4] = 3;
			liveIndices[5] = 2;

			engine::component::model_matrix_component *liveModel = new engine::component::model_matrix_component("mModel");

			engine::component::position_component *livePosition = new engine::component::position_component(std::string::basic_string
			("mOrigin"), engine::math::vector_4(1.63f, 0.89f, 0.0f, 0.0f));

			engine::component::texture_component *liveTexture = new engine::component::texture_component(std::string::basic_string("mTextureIndex"), 1);

			engine::component::vertex_component *liveVertices = new engine::component::vertex_component
			(std::string::basic_string("mVertex"), liveVertex, liveIndices);

			engine::math::vector_4 newPosition = engine::math::vector_4
			(
				livePosition->get_position()->mX - i * 0.1f,
				livePosition->get_position()->mY,
				livePosition->get_position()->mZ,
				livePosition->get_position()->mW
			);

			//liveModel->get_model_matrix()->set_identity();
			liveModel->get_model_matrix()->translate_vector(newPosition);
			liveModel->get_model_matrix()->rotate_z(0.0f);
			liveModel->get_model_matrix()->scale(1.0, 1.0, 1.0);

			mPlayerRemainingLives[i].attach_component(liveModel);
			mPlayerRemainingLives[i].attach_component(liveVertices);
			mPlayerRemainingLives[i].attach_component(livePosition);
			mPlayerRemainingLives[i].attach_component(liveTexture);
		}
		
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
		mRenderManager.generate_buffers();

		level_generator::scene firstLevel(mWidth, mHeight);
		level_generator::scene secondLevel(mWidth, mHeight);
		level_generator::scene thirdLevel(mWidth, mHeight);

		firstLevel.load_level("game/levels/first_level.txt", 3.12, 0.9);
		secondLevel.load_level("game/levels/second_level.txt", 3.12, 0.9);
		thirdLevel.load_level("game/levels/third_level.txt", 3.12, 0.9);

		this->mGameLevels.push_back(firstLevel);
		this->mGameLevels.push_back(secondLevel);
		this->mGameLevels.push_back(thirdLevel);

		mBlocks = mGameLevels[mLvl].get_blocks();
		SoundEngine->addSoundSourceFromFile("game/assets/solid.wav");
		SoundEngine->addSoundSourceFromFile("game/assets/bleep.wav");
		SoundEngine->addSoundSourceFromFile("game/assets/bleep.mp3");
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

		
		for (int i = 0; i < mBlocks.size() ; i++)
		{
				mRenderManager.render(mBlocks[i].get_component("mVertex")->get_vertex(),
				mBlocks[i].get_component("mVertex")->get_indices(),
				mBlocks[i].get_component("mTextureIndex")->get_texture_index(),
				*mBlocks[i].get_component("mModel")->get_model_matrix());
		}

		mRenderManager.render
		(
			mBall.get_component("mVertex")->get_vertex(),
			mBall.get_component("mVertex")->get_indices(),
			mBall.get_component("mTextureIndex")->get_texture_index(),
			*mBall.get_component("mModel")->get_model_matrix()
		);

		for (int i = 0; i < mPlayerLives; i++)
		{
			mRenderManager.render
			(
				mPlayerRemainingLives[i].get_component("mVertex")->get_vertex(),
				mPlayerRemainingLives[i].get_component("mVertex")->get_indices(),
				mPlayerRemainingLives[i].get_component("mTextureIndex")->get_texture_index(),
				*mPlayerRemainingLives[i].get_component("mModel")->get_model_matrix()
			);
		}
	}

	void game::update()
	{
		update_input_controller();
		mRenderManager.determine_polygon_mode();
		mGameLevels[mLvl].update_screen_dimensions(mWidth, mHeight);
		detect_screen_collision();
		paddle_collision();
		check_blocks_collision();
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
			float radians = mathUtilities.degrees_to_radians(*angle);

			position = mBall.get_component("mOrigin")->get_position();

			position->mY += (*mBall.get_component("mPhysics")->get_movement_value())*sinf(radians);
			position->mX += (*mBall.get_component("mPhysics")->get_movement_value())*cosf(radians);

			mBall.get_component("mModel")->get_model_matrix()->set_identity();
			mBall.get_component("mModel")->get_model_matrix()->translate_vector(*position);
			mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
			mBall.get_component("mModel")->get_model_matrix()->scale(1.0f, 1.0f, 1.0f);
		}
	}

	void game::detect_screen_collision()
	{
		if (mBall.get_component("mOrigin")->get_position()->mX >= 1.65f)
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
		else if (mBall.get_component("mOrigin")->get_position()->mX <= -1.65f)
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
		else if (mBall.get_component("mOrigin")->get_position()->mY <= -0.95f)
		{

			mPlayerLives--;

			if (mPlayerLives > 0)
			{
				mPlayerRemainingLives.pop_back();
			}
			
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
			SoundEngine->play2D("game/assets/bleep.mp3");
			engine::math::math_utilities RadiansToDegree;
			float angle_radians = atan2f(
				mPaddle.get_component("mOrigin")->get_position()->mY - mBall.get_component("mOrigin")->get_position()->mY,
				mPaddle.get_component("mOrigin")->get_position()->mX - mBall.get_component("mOrigin")->get_position()->mX);
			*mBall.get_component("mPhysics")->get_angle() = 180.0 + RadiansToDegree.radians_to_degrees(angle_radians);
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
		for (int i = 0; i < mBlocks.size(); i++)
		{
			if (check_ball_collision(mBlocks[i]))
			{
				engine::math::math_utilities pi;
				if(mBlocks[i].get_is_solid() == true)
				{
					SoundEngine->play2D("game/assets/solid.wav");
					if (*mBall.get_component("mPhysics")->get_angle() >= 85.0 && *mBall.get_component("mPhysics")->get_angle() <= 95.0f)
					{
						*mBall.get_component("mPhysics")->get_angle() = 270.0f;
					}
					 if (*mBall.get_component("mPhysics")->get_angle() >= 265.0 && *mBall.get_component("mPhysics")->get_angle() <= 275.0f)
					{
						*mBall.get_component("mPhysics")->get_angle() = 90.0f;
					}
				 if (*mBall.get_component("mPhysics")->get_angle() / 360.0f - (int)(*mBall.get_component("mPhysics")->get_angle() / 360) <= 0.25f)
					{
						float angle_radians = atan2f(
							mBlocks[i].get_component("mOrigin")->get_position()->mY - mBall.get_component("mOrigin")->get_position()->mY,
							mBlocks[i].get_component("mOrigin")->get_position()->mX - mBall.get_component("mOrigin")->get_position()->mX);
						if (angle_radians < pi.PI / 4 && angle_radians > -pi.PI / 4)
						{
							*mBall.get_component("mPhysics")->get_angle() += 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
						else
						{
							*mBall.get_component("mPhysics")->get_angle() -= 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
					}
					else if (*mBall.get_component("mPhysics")->get_angle() / 360.0f - (int)(*mBall.get_component("mPhysics")->get_angle() / 360) <= 0.50f)
					{
						float angle_radians = atan2f(
							mBlocks[i].get_component("mOrigin")->get_position()->mY - mBall.get_component("mOrigin")->get_position()->mY,
							mBlocks[i].get_component("mOrigin")->get_position()->mX - mBall.get_component("mOrigin")->get_position()->mX);
						if (angle_radians < pi.PI / 4 && angle_radians > -pi.PI / 4)
						{
							*mBall.get_component("mPhysics")->get_angle() -= 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
						else
						{
							*mBall.get_component("mPhysics")->get_angle() += 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
					}
					else if (*mBall.get_component("mPhysics")->get_angle() / 360.0f - (int)(*mBall.get_component("mPhysics")->get_angle() / 360) <= 0.75f)
					{
						float angle_radians = atan2f(
							mBlocks[i].get_component("mOrigin")->get_position()->mY - mBall.get_component("mOrigin")->get_position()->mY,
							mBlocks[i].get_component("mOrigin")->get_position()->mX - mBall.get_component("mOrigin")->get_position()->mX);
						if (angle_radians < pi.PI / 4 && angle_radians > -pi.PI / 4)
						{
							*mBall.get_component("mPhysics")->get_angle() += 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
						else
						{
							*mBall.get_component("mPhysics")->get_angle() -= 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
					}
					else
					{
						float angle_radians = atan2f(
							mBlocks[i].get_component("mOrigin")->get_position()->mY - mBall.get_component("mOrigin")->get_position()->mY,
							mBlocks[i].get_component("mOrigin")->get_position()->mX - mBall.get_component("mOrigin")->get_position()->mX);
						if (angle_radians < pi.PI / 4 && angle_radians > -pi.PI / 4)
						{
							*mBall.get_component("mPhysics")->get_angle() -= 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
						else
						{
							*mBall.get_component("mPhysics")->get_angle() += 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
					}

				}
				else if(mBlocks[i].get_is_solid() == false)
				{
					SoundEngine->play2D("game/assets/bleep.wav");
					mPlayerScore += mBlocks[i].get_score_value();
					if (*mBall.get_component("mPhysics")->get_angle() >= 85.0 && *mBall.get_component("mPhysics")->get_angle() <= 95.0f)
					{
						*mBall.get_component("mPhysics")->get_angle() = 270.0f;
					}
					else if (*mBall.get_component("mPhysics")->get_angle() >= 265.0 && *mBall.get_component("mPhysics")->get_angle() <= 275.0f)
					{
						*mBall.get_component("mPhysics")->get_angle() = 90.0f;
					}
					else if (*mBall.get_component("mPhysics")->get_angle() / 360.0f - (int)(*mBall.get_component("mPhysics")->get_angle() / 360) <= 0.25f)
					{
						float angle_radians = atan2f(
							mBlocks[i].get_component("mOrigin")->get_position()->mY - mBall.get_component("mOrigin")->get_position()->mY,
							mBlocks[i].get_component("mOrigin")->get_position()->mX - mBall.get_component("mOrigin")->get_position()->mX);
						if (angle_radians < pi.PI / 4 && angle_radians > -pi.PI / 4)
						{
							*mBall.get_component("mPhysics")->get_angle() += 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
						else
						{
							*mBall.get_component("mPhysics")->get_angle() -= 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
					}
					else if (*mBall.get_component("mPhysics")->get_angle() / 360.0f - (int)(*mBall.get_component("mPhysics")->get_angle() / 360) <= 0.50f)
					{
						float angle_radians = atan2f(
							mBlocks[i].get_component("mOrigin")->get_position()->mY - mBall.get_component("mOrigin")->get_position()->mY,
							mBlocks[i].get_component("mOrigin")->get_position()->mX - mBall.get_component("mOrigin")->get_position()->mX);
						if (angle_radians < pi.PI / 4 && angle_radians > -pi.PI / 4)
						{
							*mBall.get_component("mPhysics")->get_angle() -= 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
						else
						{
							*mBall.get_component("mPhysics")->get_angle() += 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
					}
					else if (*mBall.get_component("mPhysics")->get_angle() / 360.0f - (int)(*mBall.get_component("mPhysics")->get_angle() / 360) <= 0.75f)
					{
						float angle_radians = atan2f(
							mBlocks[i].get_component("mOrigin")->get_position()->mY - mBall.get_component("mOrigin")->get_position()->mY,
							mBlocks[i].get_component("mOrigin")->get_position()->mX - mBall.get_component("mOrigin")->get_position()->mX);
						if (angle_radians < pi.PI / 4 && angle_radians > -pi.PI / 4)
						{
							*mBall.get_component("mPhysics")->get_angle() += 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
						else
						{
							*mBall.get_component("mPhysics")->get_angle() -= 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
					}
					else
					{
						float angle_radians = atan2f(
							mBlocks[i].get_component("mOrigin")->get_position()->mY - mBall.get_component("mOrigin")->get_position()->mY,
							mBlocks[i].get_component("mOrigin")->get_position()->mX - mBall.get_component("mOrigin")->get_position()->mX);
						if (angle_radians < pi.PI / 4 && angle_radians > -pi.PI / 4)
						{
							*mBall.get_component("mPhysics")->get_angle() -= 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
						else
						{
							*mBall.get_component("mPhysics")->get_angle() += 180.0f - 2 * *mBall.get_component("mPhysics")->get_angle();
						}
					}
					mBlocks.erase(mBlocks.begin() + i);
				}
				bool emptyLvl = true;
				for (int i = 0; i < mBlocks.size(); i++)
				{
					if (mBlocks[i].get_is_solid() == false)
					{
						emptyLvl = false;
						break;
					}
				}

				if (emptyLvl)
				{
					mLvl++;
					mLvl = mLvl % 3;
					respawn_ball();
					mBlocks = mGameLevels[mLvl].get_blocks();
				}

				break;
			}
		}
	}

	void game::respawn_ball()
	{
		*mBall.get_component("mOrigin")->get_position() = engine::math::vector_4(0.0f, -0.9f, 0.0f, 0.0f) + engine::math::vector_4(0.0f, 0.077f, 0.0f, 0.0f);
		mBall.get_component("mOrigin")->get_position()->mX = mPaddle.get_component("mOrigin")->get_position()->mX;
		mBall.get_component("mModel")->get_model_matrix()->translate_vector(*mBall.get_component("mOrigin")->get_position());
		mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
		mBall.get_component("mModel")->get_model_matrix()->scale(1.0, 1.0, 1.0);
		mBall.set_attchToPaddle(true);
	}

	void game::create_lives()
	{
		engine::core::vertex liveVertex[36];
		int liveIndices[6];
		liveVertex[0] = { 0.03f, 0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f };
		liveVertex[1] = { 0.03f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 0.0f };
		liveVertex[2] = { -0.03f, 0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 1.0f };
		liveVertex[3] = { -0.03f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f };
		liveIndices[0] = 0;
		liveIndices[1] = 1;
		liveIndices[2] = 2;
		liveIndices[3] = 1;
		liveIndices[4] = 3;
		liveIndices[5] = 2;

		engine::component::model_matrix_component *liveModel = new engine::component::model_matrix_component("mModel");

		engine::component::position_component *livePosition = new engine::component::position_component(std::string::basic_string
		("mOrigin"), engine::math::vector_4(0.0f, -0.9f, 0.0f, 0.0f) + engine::math::vector_4(1.63f, 1.79f, 0.0f, 0.0f));

		engine::component::texture_component *liveTexture = new engine::component::texture_component(std::string::basic_string("mTextureIndex"), 1);

		engine::component::vertex_component *liveVertices = new engine::component::vertex_component
		(std::string::basic_string("mVertex"), liveVertex, liveIndices);

		liveModel->get_model_matrix()->translate_vector(*livePosition->get_position());
		liveModel->get_model_matrix()->rotate_z(0.0f);
		liveModel->get_model_matrix()->scale(1.0, 1.0, 1.0);

		mPlayerlife.attach_component(liveModel);
		mPlayerlife.attach_component(liveVertices);
		mPlayerlife.attach_component(livePosition);
		mPlayerlife.attach_component(liveTexture);
	}
}