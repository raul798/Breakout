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
		GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
	};
}
