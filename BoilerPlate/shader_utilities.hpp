#pragma once
#include <iostream>
#include <algorithm>

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


namespace engine
{
	struct shader_utilities
	{
		GLuint load_shaders(const char *pVertexFilePath, const char *pFragmentFilePath);
	};
}
