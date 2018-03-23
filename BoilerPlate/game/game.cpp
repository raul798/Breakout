#include "game.hpp"

namespace game
{
	game::game() {}

	game::~game() 
	{
		renderManager.~renderer();
	}

	void game::execute()
	{
		renderManager.assign_program_id();
		renderManager.assign_textures("game/assets/face.png");
		//renderManager.assign_textures("test.png");
		//renderManager.vertices_manager();
	}

}