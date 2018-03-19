#pragma once
#include <iostream>
#include <algorithm>

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


namespace engine
{
	class texture
	{
	public:
		texture();
		texture(const char *pTexture);
		GLuint LoadTexture(const char * texture_path);
		GLuint get_texture();

	private:
		GLuint mTexture;
	};
}