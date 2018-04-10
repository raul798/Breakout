#include "game_level.hpp"

namespace game
{
	namespace level_generator
	{
		void game_level::load_level(const char *pFile, GLuint pLevelWidth, GLfloat pLevelHeight)
		{
			// Load from file
			GLuint tileCode;
			game_level level;
			std::string line;
			std::ifstream fstream(pFile);
			std::vector<std::vector<GLuint>> tileData;
			if (fstream)
			{
				while (std::getline(fstream, line)) 
				{
					std::istringstream sstream(line);
					std::vector<GLuint> row;

					while (sstream >> tileCode) 
						row.push_back(tileCode);
					tileData.push_back(row);
				}
				if (tileData.size() > 0)
					init_level(tileData, pLevelWidth, pLevelHeight);
			}
		}

		void game_level::init_level(std::vector<std::vector<GLuint>> pTileData, GLuint pLvlWidth, GLfloat pLvlHeight)
		{
			engine::utilities::color colorManager;

			// Calculate dimensions
			GLuint height = pTileData.size();
			GLuint width = pTileData[0].size();
			GLfloat halfWidth = pLvlWidth / static_cast<GLfloat>(2);
			GLfloat unitWidth = pLvlWidth / static_cast<GLfloat>(width);
			GLfloat unitHeight = pLvlHeight / height;

			// Initialize level tiles based on tileData		
			for (GLuint y = 0; y < height; ++y)
			{
				for (GLuint x = 0; x < width; ++x)
				{
					// Check block type from level data (2D level array)
					if (pTileData[y][x] == 1) // Solid
					{
						engine::math::vector_2 position( -halfWidth + unitWidth * x, unitHeight * y);
						engine::math::vector_2 size(unitWidth, unitHeight);

						//create the object
						engine::core::block block(size, true, colorManager.GREY);
						
						*block.get_component("mOrigin")->get_position() = engine::math::vector_4(position.mX, position.mY, 0.0f, 1.0f);

						block.get_component("mModel")->get_model_matrix()->set_identity();
						block.get_component("mModel")->get_model_matrix()->translate_vector(*block.get_component("mOrigin")->get_position());
						block.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
						block.get_component("mModel")->get_model_matrix()->scale(8 * unitWidth, 8*unitHeight, 1.0f);
						mBlocks.push_back(block);
					}
					else if (pTileData[y][x] > 1)
					{
						engine::math::vector_4 color = colorManager.WHITE;

						if (pTileData[y][x] == 2)
						{
							color = colorManager.BLUE;
						}
						else if (pTileData[y][x] == 3)
						{
							color = colorManager.PURPLE;
						}
						else if (pTileData[y][x] == 4)
						{
							color = colorManager.YELLOW;
						}
						else if (pTileData[y][x] == 5)
						{
							color = colorManager.PINK;
						}
							
						engine::math::vector_2 position(-halfWidth + unitWidth * x, unitHeight * y);
						engine::math::vector_2 size(unitWidth, unitHeight);
						engine::core::block block(size, false, color);

						*block.get_component("mOrigin")->get_position() = engine::math::vector_4(position.mX, position.mY, 0.0f, 1.0f);
						block.get_component("mModel")->get_model_matrix()->set_identity();
						block.get_component("mModel")->get_model_matrix()->translate_vector(*block.get_component("mOrigin")->get_position());
						block.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
						block.get_component("mModel")->get_model_matrix()->scale(8*unitWidth, 8*unitHeight, 1.0f);

						mBlocks.push_back(block);
					}
				}
			}
		}

		std::vector<engine::core::block> game_level::get_blocks()
		{
			return mBlocks;
		}

	}
}

