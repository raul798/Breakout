#pragma once
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader_utilities.hpp"
#include "texture.hpp"
#include "vertex.hpp"

const int TEXTURE_NUMBER = 16;

namespace engine
{
	class renderer
	{
	public:
		renderer();
		~renderer();
		void assign_textures(const char pTextures[]);
		void vertices_manager();
		void render();
		void assign_program_id();
		void switch_polygon_mode();
		void determine_polygon_mode();

	private:
		GLuint mVertexArrayObject;    //VAO
		GLuint mVertexBufferObject;   //VBO
		GLuint mElementsBufferObject; //EBO
		GLuint mProgramID;
		shader_utilities mShaderManager;
		texture mTexturesContainer[TEXTURE_NUMBER];
		int mLoadedTextures;
		bool mIsPolygonModeFill;
	};
}

#endif
