#include "renderer.hpp"

namespace engine
{
	renderer::renderer(){}

	renderer::~renderer()
	{
		glDeleteBuffers(1, &mVertexBufferObject);
		glDeleteVertexArrays(1, &mVertexArrayObject);
		glDeleteProgram(mProgramID);
	}

	void renderer::assign_textures(const char *pTextures[])
	{
		for (int i = 0; i < sizeof(pTextures); i++)
		{
			mTexturesContainer[i] = texture(*pTextures);
		}
	}

	void renderer::render()
	{
		glUseProgram(mProgramID);
		glBindVertexArray(mVertexArrayObject);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	void renderer::assign_program_id()
	{
		mProgramID = mShaderManager.load_shaders("vertex.glsl", "frag.glsl");
	}

	void renderer::vertices_manager()
	{	
		float vertices[] = {
			// first triangle
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f,  0.5f, 0.0f, // top left 

			// second triangle
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f  // top left
		};

		glGenVertexArrays(1, &mVertexArrayObject);
		glGenBuffers(1, &mVertexBufferObject);

		glBindVertexArray(mVertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			3 * sizeof(float),  // stride
			(void*)0            // array buffer offset
		);
		glEnableVertexAttribArray(0);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

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