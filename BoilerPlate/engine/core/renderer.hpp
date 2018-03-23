#pragma once
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/utilities/shader_utilities.hpp"
#include "/Users/raula/source/repos/Breakout/BoilerPlate/engine/texture/texture.hpp"
#include "vertex.hpp"

const int TEXTURE_NUMBER = 16;

namespace engine
{
	namespace core
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
			GLuint mVertexArrayObject;    //VAO
			GLuint mVertexBufferObject;   //VBO
			GLuint mElementsBufferObject; //EBO
			GLuint mProgramID;
			utilities::shader_utilities mShaderManager;
			texture::texture mTexturesContainer[TEXTURE_NUMBER];
			bool mIsPolygonModeFill;
		};
	}
}

#endif