#include "game_level.hpp"

namespace game
{
	namespace level_generator
	{
		const float NORMAL_SCREEN_HEIGHT_FACTOR = 1.0/640.0;
		const float NORMAL_SCREEN_WIDTH_FACTOR = 1.0/1136.0;
		game_level::game_level() {}

		game_level::game_level(int pWidth, int pHeight)
		{
			mGameLevelWidth = pWidth;
			mGameLevelHeight = pHeight;
		}

		void game_level::load_level(const char *pFile, float pLevelWidth, float pLevelHeight)
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

		void game_level::init_level(std::vector<std::vector<GLuint>> pTileData, float pLvlWidth, float pLvlHeight)
		{
			engine::utilities::color colorManager;
			float heightFactor = NORMAL_SCREEN_HEIGHT_FACTOR * mGameLevelHeight;
			float widthFactor = NORMAL_SCREEN_WIDTH_FACTOR * mGameLevelWidth;

			// Calculate dimensions
			GLuint height = pTileData.size();
			GLuint width = pTileData[0].size();
			GLuint screenWidth = width - 1;
			float halfWidth = pLvlWidth / static_cast<GLfloat>(2);
			float unitWidth = pLvlWidth / static_cast<GLfloat>(screenWidth);
			float unitHeight = pLvlHeight / height;

			// Initialize level tiles based on tileData		
			for (GLuint y = 0; y < height; ++y)
			{
				for (GLuint x = 0; x < width; ++x)
				{
					// Check block type from level data (2D level array)
					if (pTileData[y][x] == 1) // Solid
					{
						engine::math::vector_2 position( -halfWidth + unitWidth * x, unitHeight * y);
						engine::math::vector_2 size(widthFactor * 10 * unitWidth, heightFactor * 10 * unitHeight);

						//create the object
						engine::core::block block(size, true, colorManager.GREY);
						
						*block.get_component("mOrigin")->get_position() = engine::math::vector_4(position.mX, position.mY, 0.0f, 1.0f);

						block.get_component("mModel")->get_model_matrix()->set_identity();
						block.get_component("mModel")->get_model_matrix()->translate_vector(*block.get_component("mOrigin")->get_position());
						block.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
						block.get_component("mModel")->get_model_matrix()->scale(widthFactor * 10 *  unitWidth, heightFactor * 10 * unitHeight, 1.0f);
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
						engine::math::vector_2 size(widthFactor * 10 * unitWidth, heightFactor * 10 * unitHeight);
						engine::core::block block(size, false, color);

						*block.get_component("mOrigin")->get_position() = engine::math::vector_4(position.mX, position.mY, 0.0f, 1.0f);
						block.get_component("mModel")->get_model_matrix()->set_identity();
						block.get_component("mModel")->get_model_matrix()->translate_vector(*block.get_component("mOrigin")->get_position());
						block.get_component("mModel")->get_model_matrix()->rotate_z(0.0f);
						block.get_component("mModel")->get_model_matrix()->scale(widthFactor * 10 * unitWidth, heightFactor * 10 * unitHeight, 1.0f);

						mBlocks.push_back(block);
					}
				}
			}
		}

		void game_level::update_screen_dimensions(int pWidth, int pHeight)
		{
			mGameLevelWidth = pWidth;
			mGameLevelHeight = pHeight;
		}

		std::vector<engine::core::block> game_level::get_blocks()
		{
			return mBlocks;
		}

	}
}

