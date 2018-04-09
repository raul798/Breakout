#pragma once
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

#include "../utilities/shader_utilities.hpp"
#include "../texture/texture_manager.hpp"
#include "vertex.hpp"
#include "../math/Matrix_4.hpp"

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
			void assign_textures(const char pTextures[]);
			void vertices_manager(vertex *pVertices[], int *pIndices[]);
			void render(vertex pVertices[], int pIndices[], int pTextureIndex, math::matrix_4 pModelMatrix);
			void assign_program_id();
			void switch_polygon_mode();
			void determine_polygon_mode();
			void generate_buffers();
			void update_screen_parameters(int pWidth, int pHeight);

		private:
			GLuint mVertexArrayObject;    //VAO
			GLuint mVertexBufferObject;   //VBO
			GLuint mElementsBufferObject; //EBO
			GLuint mProgramID;
			utilities::shader_utilities mShaderManager;
			texture::texture_manager mTexturesContainer[TEXTURE_NUMBER];
			int mLoadedTextures;
			int mWidth;
			int mHeight;
			bool mIsPolygonModeFill;
		};
	}
}

#endif
