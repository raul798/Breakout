#pragma once
#ifndef GAME_LEVEL_HPP
#define GAME_LEVEL_HPP

#include <sstream>
#include <fstream>
#include <GL/glew.h>

#include "../BoilerPlate//engine/math/vector_4.hpp"
#include "../BoilerPlate/engine/core/block.hpp"
#include "../BoilerPlate//engine/texture/texture_manager.hpp"
#include "../BoilerPlate//engine/utilities/color.hpp"

namespace game
{
	namespace level_generator
	{
		class game_level
		{
		public:
			//constructor
			game_level(int pWidth, int pHeight);
			game_level();

			//functions
			void load_level(const char *pFile, float pLevelWidth, float pLevelHeight);
			void init_level(std::vector<std::vector<GLuint>> tileData, float levelWidth, float levelHeight);
			void update_screen_dimensions(int pWidth, int pHeight);
			std::vector<engine::core::block> mBlocks;

			//gettter
			std::vector<engine::core::block> get_blocks();
			
		private:
			
			int mGameLevelWidth;
			int mGameLevelHeight;
			
			
		};
	}
}

#endif