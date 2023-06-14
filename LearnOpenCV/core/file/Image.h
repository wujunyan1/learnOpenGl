#pragma once
#include <iostream>
#include <GL/glew.h>
#include <vector>

namespace Core
{
	class Image
	{
	public:
		enum IMAGE_TYPE
		{
			TEXTURE_2D = GL_TEXTURE_2D,
			TEXTURE_CUBE_MAP = GL_TEXTURE_CUBE_MAP,
		};

	public:
		Image(std::string& name, IMAGE_TYPE type)
		{
			this->name = name;
			m_type = type;
		}

		~Image()
		{
			glDeleteTextures(1, &textureID);
		}


		virtual void use(int textureIndex)
		{
			//glDepthMask(GL_FALSE);                                                         //�ص���Ȳ���     
			//glEnable(GL_BLEND);                                                            //�����ģʽ��ͼ     
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);                             //���û�Ϸ�ʽ 
			//GL_ZERO

			//GL_BLEND

			glActiveTexture(Image::textureIndex[textureIndex]);
			glBindTexture(GL_TEXTURE_2D, textureID);
			//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);			//��ͼģʽΪ���
		}

		void exit(int textureIndex)
		{

		}

		const unsigned int getTextureId() { return textureID; };
		const std::string& getName() { return name; };

		void setBlendFunc();

	public:
		static const int textureIndex[32];

	protected:
		std::string name;
		IMAGE_TYPE m_type;

		unsigned int textureID;
		int width, height, nrChannels;
	};


	class Image2D : public Image
	{
	public:
		Image2D(std::string& path, int width, int height, int nrChannels, unsigned char* data):Image(path, Image::IMAGE_TYPE::TEXTURE_2D)
		{
			this->name = path;
			this->width = width;
			this->height = height;
			this->nrChannels = nrChannels;

			printf("%x\n", nrChannels);
			glGenTextures(1, &textureID); // ��������

			glBindTexture(GL_TEXTURE_2D, textureID);

			/*GL_NEAREST_MIPMAP_NEAREST
			ʹ�����ڽ��Ķ༶��Զ������ƥ�����ش�С����ʹ���ڽ���ֵ�����������
			GL_LINEAR_MIPMAP_NEAREST
			ʹ�����ڽ��Ķ༶��Զ�����𣬲�ʹ�����Բ�ֵ���в���
			GL_NEAREST_MIPMAP_LINEAR
			��������ƥ�����ش�С�Ķ༶��Զ����֮��������Բ�ֵ��ʹ���ڽ���ֵ���в���
			GL_LINEAR_MIPMAP_LINEAR
			�������ڽ��Ķ༶��Զ����֮��ʹ�����Բ�ֵ����ʹ�����Բ�ֵ���в���*/

			//// Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			switch (nrChannels)
			{
			case 3:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				break;
			case 4:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				break;
			default:
				break;
			}
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		virtual void use(int textureIndex)
		{
			//glDepthMask(GL_FALSE);                                                         //�ص���Ȳ���     
			//glEnable(GL_BLEND);                                                            //�����ģʽ��ͼ     
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);                             //���û�Ϸ�ʽ 
			//GL_ZERO

			//GL_BLEND

			glBindTexture(GL_TEXTURE_2D, textureID);
			glActiveTexture(Image::textureIndex[textureIndex]);
			//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);			//��ͼģʽΪ���
		}

	};

	class ImageCubeMap : public Image
	{
	public:
		ImageCubeMap(std::string& name, std::vector<std::string>& faces);

		virtual void use(int textureIndex)
		{

			glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
			glActiveTexture(Image::textureIndex[textureIndex]);
		}

	private:
	};

	class ImageFont : public Image
	{
	public:
		ImageFont(std::string& name, unsigned int textureID);

		virtual void use(int textureIndex)
		{
			glBindTexture(GL_TEXTURE_2D, textureID);
			glActiveTexture(Image::textureIndex[textureIndex]);
		}

	private:
	};
}