#define STB_IMAGE_IMPLEMENTATION

#include "texture_manager.hpp"

namespace engine
{
	namespace texture
	{
		texture_manager::texture_manager() {}

		texture_manager::texture_manager(const char *pTexture)
		{
			mTexture = load_texture(pTexture);
		}

		GLuint texture_manager::get_texture()
		{
			return mTexture;
		}

		GLuint texture_manager::load_texture(const char *pTexturePath)
		{
			unsigned int texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			//set the texture wrapping/filtering options (on the currently bound texture object)
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			int width, height, nrChannels;
			//flip y 
			stbi_set_flip_vertically_on_load(true);

			//load the texture
			unsigned char *data = stbi_load(pTexturePath, &width, &height, &nrChannels, 0);
			if (data)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else
			{
				std::cout << "Failed to load texture" << std::endl;
				return -1;
			}
			stbi_image_free(data);

			return texture;
		}
	}
}