#include "game.hpp"

namespace game
{
	game::game()
	{
		mInputCounter = 0;
		mBlockCounter = 0;
		create_ball();
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
		mRenderManager.render
		(
			mBlock.get_component("mVertex")->get_vertex(), 
			mBlock.get_component("mVertex")->get_indices(), 
			mBlock.get_texture_index(), 
			*mBlock.get_component("mModel")->get_model_matrix()
		);

		mRenderManager.render
		(
			mBall.get_component("mVertex")->get_vertex(),
			mBall.get_component("mVertex")->get_indices(),
			mBall.get_texture_index(), 
			*mBall.get_component("mModel")->get_model_matrix()
		);
	}

	void game::update()
	{
		update_input_controller();
		mRenderManager.determine_polygon_mode();
		//borrar
		movement();

		if (mBlockCounter == 0)
		{
			create_block();
			mBlockCounter++;
		}
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

	void game::create_ball()
	{
		std::vector<engine::core::vertex> ballVertex;
		std::vector<int> ballIndices;
		ballVertex.push_back({ 0.03f, 0.03f, 0.0f,    1.0f, 0.0f, 0.0f, 1.0f,  1.0f, 1.0f });
		ballVertex.push_back({ 0.03f, -0.03f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,  1.0f, 0.0f });
		ballVertex.push_back({ -0.03f, 0.03f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 1.0f });
		ballVertex.push_back({ -0.03f, -0.03f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f });
		ballIndices.push_back(0);
		ballIndices.push_back(1);
		ballIndices.push_back(2);
		ballIndices.push_back(1);
		ballIndices.push_back(3);
		ballIndices.push_back(2);
		ballIndices.push_back(0);

		engine::component::model_matrix_component *ballModel = new engine::component::model_matrix_component("mModel");

		engine::component::position_component *ballPosition = new engine::component::position_component(std::string::basic_string("mOrigin"));

		engine::component::phisics_component *ballPhisics = new engine::component::phisics_component
		(std::string::basic_string("mPhisics"), engine::math::vector_4(0.0f, 0.0f, 0.0f, 0.0f), 0.001f);

		engine::component::vertex_component *ballVertices = new engine::component::vertex_component
		(std::string::basic_string("mVertex"), ballVertex, ballIndices);

		mBall.attach_component(ballModel);
		mBall.attach_component(ballVertices);
		mBall.attach_component(ballPosition);
		mBall.attach_component(ballPhisics);
	}

	void game::create_block()
	{
		std::vector<engine::core::vertex> blockVertex;
		std::vector<int> blockIndices;
		blockVertex.push_back({ 0.06f, 0.06f, 0.0f,    1.0f, 0.0f, 0.0f, 1.0f,   1.0f, 1.0f });
		blockVertex.push_back({ 0.06f, -0.06f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,   1.0f, 0.0f });
		blockVertex.push_back({ -0.06f, 0.06f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,   0.0f, 1.0f });
		blockVertex.push_back({ -0.06f, -0.06f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,   0.0f, 0.0f });
		blockIndices.push_back(0);
		blockIndices.push_back(1);
		blockIndices.push_back(2);
		blockIndices.push_back(1);
		blockIndices.push_back(3);
		blockIndices.push_back(2);
		blockIndices.push_back(0);

		engine::component::model_matrix_component *blockModel = new engine::component::model_matrix_component("mModel");

		engine::component::position_component *blockPosition = new engine::component::position_component
		(std::string::basic_string("mOrigin"), engine::math::vector_4(0.0f, 0.6f, 0.0f, 0.0f));

		engine::component::vertex_component *blockVertices = new engine::component::vertex_component
		(std::string::basic_string("mVertex"), blockVertex, blockIndices);

		blockModel->get_model_matrix()->translate_vector(*blockPosition->get_position());
		blockModel->get_model_matrix()->rotate_z(0.0f);

		mBlock.attach_component(blockModel);
		mBlock.attach_component(blockVertices);
		mBlock.attach_component(blockPosition);
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
	}
}