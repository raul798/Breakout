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
		renderer();
		~renderer();
		void assign_textures(const char *pTextures[]);
		void vertices_manager();
		void render();
		void assign_program_id();
		void switch_polygon_mode();
		void determine_polygon_mode();

	private:
		GLuint mVertexArrayObject; //VAO
		GLuint mVertexBufferObject; //VBO
		GLuint mProgramID;
		shader_utilities mShaderManager;
		texture mTexturesContainer[TEXTURE_NUMBER];
		bool mIsPolygonModeFill;
	};
}
