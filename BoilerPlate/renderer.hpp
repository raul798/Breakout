#pragma once
#include <iostream>
#include <algorithm>

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

#include "shader_utilities.hpp"
#include "texture.hpp"

const int TEXTURE_NUMBER = 16;

namespace engine
{
	class renderer
	{
	public:
		renderer(const char *pTextures[]);
		~renderer();
		void assign_textures(const char *pTextures[]);
		void vertices_manager();
		void render();

	private:
		GLuint VertexArrayObject; //VAO
		GLuint VertexBufferObject; //VBO
		GLuint ProgramID;
		shader_utilities mShaderManager;
		texture mTexturesContainer[TEXTURE_NUMBER];
	};
}
