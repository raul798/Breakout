#pragma once
#ifndef TEXT_MANAGER_HPP
#define TEXT_MANAGER_HPP

#include <string>
#include <iostream>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "SDLEvent.hpp"

namespace engine
{
	namespace utilities
	{
		class text_manager {

		private:
			TTF_Font * font;

		public:
			text_manager(int pFontSize);
			bool init_font();
			unsigned int power_two_floor(unsigned int pVal);
			void render_text(std::string pMessage, SDL_Color pColor, float pX, float pY, int pSize);
		};
	}
}



#endif
