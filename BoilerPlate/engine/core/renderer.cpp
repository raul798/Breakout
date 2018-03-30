#include "renderer.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace engine
{
	namespace core
	{
		renderer::renderer()
		{
			mIsPolygonModeFill = true;
			mLoadedTextures = 0;
		}

		renderer::~renderer()
		{
			glDeleteBuffers(1, &mVertexBufferObject);
			glDeleteVertexArrays(1, &mVertexArrayObject);
			glDeleteProgram(mProgramID);
		}

		void renderer::assign_textures(const char pTextures[])
		{

			mTexturesContainer[mLoadedTextures] = texture::texture_manager(pTextures);
			
			mLoadedTextures++;
		}

		void renderer::render(vertex pVertices[], int pIndices[], int pTextureIndex, math::matrix_4 pModelMatrix)
		{
			int localIndices[sizeof(pIndices)];

			for (int i = 0; i < sizeof(pIndices); i++)
			{
				localIndices[i] = pIndices[i];
			}

			vertices_manager(pVertices, pIndices);

			
			glUseProgram(mProgramID);
			math::matrix_4 model = math::matrix_4();
			math::matrix_4 view = math::matrix_4();
			math::matrix_4 projection = math::matrix_4();

			model.translate_vector(math::vector_4(0.0f, 0.80f, 0.0f, 1.0f));
			model.rotate_z(0.0f);

			view.translate_vector(math::vector_4(0.0f, 0.0f, -3.0f, 1.0f));
			view.rotate_z(0.0f);
			projection.make_perspective(30.0f, 0.1f, 100.0f, (float)mHeight/mWidth);

			// retrieve the matrix uniform locations
			GLuint modelLoc = glGetUniformLocation(mProgramID, "model");
			GLuint viewLoc = glGetUniformLocation(mProgramID, "view");
			GLuint projectionLoc = glGetUniformLocation(mProgramID, "projection");

			float modelMatrix[16];
			float viewMatrix[16];
			float projectionMatrix[16];

			pModelMatrix.assign_matrix(modelMatrix);
			view.assign_matrix(viewMatrix);
			projection.assign_matrix(projectionMatrix);

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelMatrix);

			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, viewMatrix);
			glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projectionMatrix);
	
			float resolution[] = { static_cast<float>(1136), static_cast<float>(640) };

			glBindVertexArray(mVertexArrayObject);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, mTexturesContainer[pTextureIndex].get_texture());

			glDrawElements(GL_TRIANGLES, sizeof(localIndices), GL_UNSIGNED_INT, (void*)0);
		}

		void renderer::assign_program_id()
		{
			mProgramID = mShaderManager.load_shaders("vertex.glsl", "frag.glsl");
		}

		void renderer::generate_buffers()
		{
			glGenVertexArrays(1, &mVertexArrayObject);
			glGenBuffers(1, &mVertexBufferObject);
			glGenBuffers(1, &mElementsBufferObject);
		}

		void renderer::vertices_manager(vertex pVertices[], int pIndices[])
		{
			vertex localVertex[sizeof(pVertices)];
			int localIndices[sizeof(pIndices)];

			for (int i = 0; i < sizeof(pVertices); i++)
			{
				localVertex[i] = pVertices[i];
			}

			for (int i = 0; i < sizeof(pIndices); i++)
			{
				localIndices[i] = pIndices[i];
			}

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);

			// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
			glBindVertexArray(mVertexArrayObject);

			glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
			glBufferData(GL_ARRAY_BUFFER, sizeof(localVertex), localVertex, GL_STATIC_DRAW);


			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(localIndices), localIndices, GL_STATIC_DRAW);

			//vertex position
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			//color
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);
			//texture coordinate
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
			glEnableVertexAttribArray(2);

			// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
			// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
			glBindVertexArray(0);
		}

		void renderer::determine_polygon_mode()
		{
			if (mIsPolygonModeFill == true)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else if (mIsPolygonModeFill == false)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
		}

		void renderer::switch_polygon_mode()
		{
			if (mIsPolygonModeFill == true)
			{
				mIsPolygonModeFill = false;
			}
			else
			{
				mIsPolygonModeFill = true;
			}
		}

		void renderer::update_screen_parameters(int pWidth, int pHeight)
		{
			mWidth = pWidth;
			mHeight = pHeight;
		}
	}
}