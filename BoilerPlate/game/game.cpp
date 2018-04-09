#include "game.hpp"

namespace game
{
	game::game(){}

	game::game(int width, int height)
	{
		mInputCounter = 0;
		mBlockCounter = 0;

		create_paddle();
		create_ball();	
		
		mWidth = width;
		mHeight = height;
	}

	game::~game()
	{
		//mRenderManager.~renderer();
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

		level::game_level one;
		//one.load_level("game/assets/first_level.txt", mWidth, mHeight*0.5);
		one.load_level("game/assets/first_level.txt", 2.0, 0.5);

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

		for (int i = 0; i < mGameLevels[0].get_blocks().size() ; i++)
		{
			mRenderManager.render(mGameLevels[0].get_blocks()[i].get_component("mVertex")->get_vertex(),
				mGameLevels[0].get_blocks()[i].get_component("mVertex")->get_indices(),
				mGameLevels[0].get_blocks()[i].get_component("mTextureIndex")->get_texture_index(),
				*mGameLevels[0].get_blocks()[i].get_component("mModel")->get_model_matrix());
				
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
			create_block();
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
			mPaddle.get_component("mModel")->get_model_matrix()->scale(2.0f, 2.0f, 1.0f);
			mPaddle.get_component("mModel")->get_model_matrix()->translate_vector(*mPaddle.get_component("mOrigin")->get_position());
			mPaddle.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);

			if (mBall.get_AttchToPaddle() == true)
			{
				mBall.get_component("mOrigin")->get_position()->mX -= *mPaddle.get_component("mPhisics")->get_movement_value();

				mBall.get_component("mModel")->get_model_matrix()->set_identity();
				mBall.get_component("mModel")->get_model_matrix()->scale(2.0f, 2.0f, 1.0f);
				mBall.get_component("mModel")->get_model_matrix()->translate_vector(*mBall.get_component("mOrigin")->get_position());
				mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
			}
		}

		if (mInputManager.get_d())
		{
			mPaddle.get_component("mOrigin")->get_position()->mX += *mPaddle.get_component("mPhisics")->get_movement_value();

			mPaddle.get_component("mModel")->get_model_matrix()->set_identity();
			mPaddle.get_component("mModel")->get_model_matrix()->scale(2.0f, 2.0f, 1.0f);
			mPaddle.get_component("mModel")->get_model_matrix()->translate_vector(*mPaddle.get_component("mOrigin")->get_position());
			mPaddle.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);

			if (mBall.get_AttchToPaddle() == true)
			{
				mBall.get_component("mOrigin")->get_position()->mX += *mPaddle.get_component("mPhisics")->get_movement_value();

				mBall.get_component("mModel")->get_model_matrix()->set_identity();
				mBall.get_component("mModel")->get_model_matrix()->scale(2.0f, 2.0f, 1.0f);
				mBall.get_component("mModel")->get_model_matrix()->translate_vector(*mBall.get_component("mOrigin")->get_position());
				mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
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

	void game::create_ball()
	{
		engine::core::vertex ballVertex[36];
		int ballIndices[6];
		ballVertex[0] = { 0.06f, 0.06f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,  1.0f, 1.0f };
		ballVertex[1] = { 0.06f, -0.06f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  1.0f, 0.0f };
		ballVertex[2] = { -0.06f, 0.06f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 1.0f };
		ballVertex[3] = { -0.06f, -0.06f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f };
		ballIndices[0] = 0;
		ballIndices[1] = 1;
		ballIndices[2] = 2;
		ballIndices[3] = 1;
		ballIndices[4] = 3;
		ballIndices[5] = 2;
		//ballIndices.push_back(0);

		engine::component::model_matrix_component *ballModel = new engine::component::model_matrix_component("mModel");

		engine::component::position_component *ballPosition = new engine::component::position_component(std::string::basic_string
		("mOrigin"), *mPaddle.get_component("mOrigin")->get_position() + engine::math::vector_4(0.0f, 0.077f, 0.0f, 0.0f));

		engine::component::texture_component *ballTexture = new engine::component::texture_component(std::string::basic_string("mTextureIndex"), 1);

		engine::component::phisics_component *ballPhisics = new engine::component::phisics_component
		(std::string::basic_string("mPhisics"), 0.001f);

		engine::component::vertex_component *ballVertices = new engine::component::vertex_component
		(std::string::basic_string("mVertex"), ballVertex, ballIndices);

		ballModel->get_model_matrix()->scale(2.0, 2.0, 1.0);
		ballModel->get_model_matrix()->translate_vector(*ballPosition->get_position());
		ballModel->get_model_matrix()->rotate_z(0.0f);

		mBall.attach_component(ballModel);
		mBall.attach_component(ballVertices);
		mBall.attach_component(ballPosition);
		mBall.attach_component(ballPhisics);
		mBall.attach_component(ballTexture);
	}

	void game::create_block()
	{}
		

	void game::create_paddle()
	{
		engine::core::vertex paddleVertex[36];
		int paddleIndices[6];
		paddleVertex[0] = { 0.06f, 0.06f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,  1.0f, 1.0f };
		paddleVertex[1] = { 0.06f, -0.06f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  1.0f, 0.0f };
		paddleVertex[2] = { -0.06f, 0.06f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 1.0f };
		paddleVertex[3] = { -0.06f, -0.06f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f };
		paddleIndices[0] = 0;
		paddleIndices[1] = 1;
		paddleIndices[2] = 2;
		paddleIndices[3] = 1;
		paddleIndices[4] = 3;
		paddleIndices[5] = 2;

		engine::component::model_matrix_component *paddleModel = new engine::component::model_matrix_component("mModel");

		engine::component::position_component *paddlePosition = new engine::component::position_component
		(std::string::basic_string("mOrigin"), engine::math::vector_4(0.0f, -0.9f, 0.0f, 0.0f));

		engine::component::texture_component *paddleTexture = new engine::component::texture_component(std::string::basic_string("mTextureIndex"), 3);

		engine::component::phisics_component *paddlePhisics = new engine::component::phisics_component
		(std::string::basic_string("mPhisics"), 0.02f);

		engine::component::vertex_component *paddleVertices = new engine::component::vertex_component
		(std::string::basic_string("mVertex"), paddleVertex, paddleIndices);

		paddleModel->get_model_matrix()->scale(2.0f, 2.0f, 1.0f);
		paddleModel->get_model_matrix()->translate_vector(*paddlePosition->get_position());
		paddleModel->get_model_matrix()->rotate_z(0.0f);

		mPaddle.attach_component(paddleModel);
		mPaddle.attach_component(paddleVertices);
		mPaddle.attach_component(paddlePosition);
		mPaddle.attach_component(paddlePhisics);
		mPaddle.attach_component(paddleTexture);
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
		mBall.get_component("mModel")->get_model_matrix()->scale(2.0f, 2.0f, 1.0f);
		mBall.get_component("mModel")->get_model_matrix()->translate_vector(*position);
		mBall.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
	}
}