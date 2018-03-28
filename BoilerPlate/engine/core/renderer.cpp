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

		void renderer::render(vertex pVertices[], int pIndices[], int pTextureIndex)
		{
			int localIndices[sizeof(pIndices)];

			for (int i = 0; i < sizeof(pIndices); i++)
			{
				localIndices[i] = pIndices[i];
			}

			vertices_manager(pVertices, pIndices);

			
			glUseProgram(mProgramID);
			//glm::mat4 model;
			//glm::mat4 view;
			glm::mat4 projection;

			//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
			//model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
			projection = glm::perspective(glm::radians(45.0f), static_cast<float>(1136) / static_cast<float>(640), 0.1f, 100.0f);
			math::matrix_4 model = math::matrix_4();
			math::matrix_4 view = math::matrix_4();
			model.translate_vector(math::vector_4(0.0f, 0.0f, 0.30f, 1.0f));
			model.rotate_z(0.0f);
			view.translate_vector(math::vector_4(0.0f, 0.0f, -3.0f, 1.0f));
			// retrieve the matrix uniform locations
			GLuint modelLoc = glGetUniformLocation(mProgramID, "model");
			GLuint viewLoc = glGetUniformLocation(mProgramID, "view");
			GLuint projectionLoc = glGetUniformLocation(mProgramID, "projection");

			//std::cout << model;
			float modelMatrix[16];
			float viewMatrix[16];
			model.get_matrix(modelMatrix);
			view.get_matrix(viewMatrix);
			glUniformMatrix4fv(modelLoc, 1, GL_TRUE, modelMatrix);
			glUniformMatrix4fv(viewLoc, 1, GL_TRUE, viewMatrix);

			//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
				
			float resolution[] = { static_cast<float>(1136), static_cast<float>(640) };

			glBindVertexArray(mVertexArrayObject);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, mTexturesContainer[pTextureIndex].get_texture());

			glDrawElements(GL_TRIANGLES, sizeof(localIndices), GL_UNSIGNED_INT, (void*)0);
			/*std::cout << view[0][0] << view[0][1] << view[0][2] << view[0][3] << std::endl
				<< view[1][0] << view[1][1] << view[1][2] << view[1][3] << std::endl
				<< view[2][0] << view[2][1] << view[2][2] << view[2][3] << std::endl
				<< view[3][0] << view[3][1] << view[3][2] << view[3][3] << std::endl;*/
			/*std::cout << a[0] << a[1] << a[2] << a[3] << std::endl
				<< a[4] << a[5] << a[6] << a[7] << std::endl
				<< a[8] << a[9] << a[10] << a[11] << std::endl
				<< a[12] << a[13] << a[14] << a[15] << std::endl;*/
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
	}
}