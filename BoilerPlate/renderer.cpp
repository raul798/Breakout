#include "renderer.hpp"

namespace engine
{
	vertex vertices[] = {
		// positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	int indices[] = { 0, 1, 2, 1, 3, 2 };

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

		mTexturesContainer[mLoadedTextures] = texture(pTextures);
		glUniform1i(glGetUniformLocation(mProgramID, "texture1"), 0);

		mLoadedTextures++;
	}

	void renderer::render()
	{
		glUseProgram(mProgramID);

		// Remember this needs to be set after the program is activated
		glUniform1i(glGetUniformLocation(mProgramID, "texture1"), 0);
		//glUniform1i(glGetUniformLocation(mProgramID, "texture2"), 1);

		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mTexturesContainer[0].get_texture());

		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, (void*)0);
	}

	void renderer::assign_program_id()
	{
		mProgramID = mShaderManager.load_shaders("vertex.glsl", "frag.glsl");
	}

	void renderer::vertices_manager()
	{	
		glGenVertexArrays(1, &mVertexArrayObject);
		glGenBuffers(1, &mVertexBufferObject);
		glGenBuffers(1, &mElementsBufferObject);
	

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(mVertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		/*glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			4 * sizeof(float),  // stride
			(void*)0            // array buffer offset
			);

		glEnableVertexAttribArray(0);*/
		//vertex position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		//color
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		//texture coordinate
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

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