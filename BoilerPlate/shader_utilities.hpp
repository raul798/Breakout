#pragma once
#ifndef SHADER_UTILITIES_HPP
#define SHADER_UTILITIES_HPP

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

#include "error_manager.hpp"
#include "stb_image.h"

namespace engine
{
	struct shader_utilities
	{
		GLuint load_shaders(const char *pVertexFilePath, const char *pFragmentFilePath);
	};
}

#endif
