#pragma once
#ifndef GAME_LEVEL_HPP
#define GAME_LEVEL_HPP

#include <sstream>
#include <fstream>
#include <GL/glew.h>

#include "../BoilerPlate//engine/math/vector_4.hpp"
#include "../BoilerPlate/engine/core/block.hpp"
#include "../BoilerPlate//engine/texture/texture_manager.hpp"

namespace game
{
	namespace level
	{
		class game_level
		{
		public:
			//constructor
			game_level() {}

			//functions
			void load_level(const char *pFile, GLuint pLevelWidth, GLuint pLevelHeight);
			void init_level(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight);

			//gettter
			std::vector<engine::core::block> get_blocks();
			
		private:
			std::vector<engine::core::block> mBlocks;
			
			
		};
	}
}

#endif