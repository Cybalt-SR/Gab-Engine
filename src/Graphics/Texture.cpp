#include "Texture.h"

namespace gde {
	using namespace rendering;
	Texture::Texture(const char* path) {
		std::string pathstr = path;

		stbi_set_flip_vertically_on_load(true);
		tex_bytes = stbi_load(path, &img_width, &img_height, &colorchannels, 0);
		glGenTextures(1, &texID);
		glBindTexture(GL_TEXTURE_2D, texID);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_bytes);

		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(tex_bytes);
	}

	TextureCubeMap::TextureCubeMap(std::string semiPath, std::string fileExtension) {
		std::string texPaths[6]{
			semiPath + "_rt." + fileExtension,
			semiPath + "_lf." + fileExtension,
			semiPath + "_up." + fileExtension,
			semiPath + "_dn." + fileExtension,
			semiPath + "_ft." + fileExtension,
			semiPath + "_bk." + fileExtension
		};

		glGenTextures(1, &texID);
		glBindTexture(GL_TEXTURE_CUBE_MAP, texID);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		for (int i = 0; i < 6; i++)
		{
			int w, h, skyCChannel;
			stbi_set_flip_vertically_on_load(false);
			unsigned char* data = stbi_load(texPaths[i].c_str(), &w, &h, &skyCChannel, 0);

			if (data) {
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				stbi_image_free(data);
			}
		}

		stbi_set_flip_vertically_on_load(true);

		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	}
}