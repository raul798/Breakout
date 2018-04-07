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
			std::vector<engine::core::block> blocks;

			game_level() { }
			// Loads level from file
			void load_level(const char *pFile, GLuint pLevelWidth, GLuint pLevelHeight);
			// Render level
			void draw_level();
			// Check if the level is completed (all non-solid tiles are destroyed)
			bool is_completed();

		private:
			// Initialize level from tile data
			void init_level(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight);
		};
	}
}

#endif