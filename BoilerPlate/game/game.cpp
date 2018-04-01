#include "game.hpp"

namespace game
{
	game::game()
	{
		mInputCounter = 0;
		mBlockCounter = 0;
		add_player_component();
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
		mRenderManager.render(mBlock.GetComponents()[1]->get_vertex(), mBlock.GetComponents()[1]->get_indices(), mBlock.get_texture_index(), *mBlock.GetComponents()[0]->get_model_matrix());
		mRenderManager.render(mBall.GetComponents()[1]->get_vertex(), mBall.GetComponents()[1]->get_indices(), mBall.get_texture_index(), *mBall.GetComponents()[0]->get_model_matrix());
	}

	void game::update()
	{
		update_input_controller();
		mRenderManager.determine_polygon_mode();
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

	void game::add_player_component()
	{
		engine::component::model_matrix_component* ballModel = new engine::component::model_matrix_component("mModel");
		mBall.attach_component(ballModel);
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
		engine::component::vertex_component* ballVertices = new engine::component::vertex_component(std::string::basic_string("mVertex"), ballVertex, ballIndices);
		mBall.attach_component(ballVertices);

	}

	void game::create_block()
	{
		engine::component::model_matrix_component* blockModel = new engine::component::model_matrix_component("mModel");
		blockModel->get_model_matrix()->translate_vector(engine::math::vector_4(0.0f, 0.6f, 0.0f, 1.0f));
		blockModel->get_model_matrix()->rotate_z(0.5f);
		mBlock.attach_component(blockModel);
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
		engine::component::vertex_component* blockVertices = new engine::component::vertex_component(std::string::basic_string("mVertex"), blockVertex, blockIndices);
		mBlock.attach_component(blockVertices);
	}
}