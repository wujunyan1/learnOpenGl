#pragma once
#include <iostream>
#include <GL/glew.h>

class Image
{

public:
	Image(int width, int height, int nrChannels, unsigned char* data) :width(width), height(height), nrChannels(nrChannels)
	{
		printf("%x\n", nrChannels);
		glGenTextures(1, &texture); // ��������

		glBindTexture(GL_TEXTURE_2D, texture);

			/*GL_NEAREST_MIPMAP_NEAREST
			ʹ�����ڽ��Ķ༶��Զ������ƥ�����ش�С����ʹ���ڽ���ֵ�����������
			GL_LINEAR_MIPMAP_NEAREST
			ʹ�����ڽ��Ķ༶��Զ�����𣬲�ʹ�����Բ�ֵ���в���
			GL_NEAREST_MIPMAP_LINEAR
			��������ƥ�����ش�С�Ķ༶��Զ����֮��������Բ�ֵ��ʹ���ڽ���ֵ���в���
			GL_LINEAR_MIPMAP_LINEAR
			�������ڽ��Ķ༶��Զ����֮��ʹ�����Բ�ֵ����ʹ�����Բ�ֵ���в���*/

		//// Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

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

	void use(int textureIndex) 
	{
		//glDepthMask(GL_FALSE);                                                         //�ص���Ȳ���     
		glEnable(GL_BLEND);                                                            //�����ģʽ��ͼ     
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);                             //���û�Ϸ�ʽ 

		glBindTexture(GL_TEXTURE_2D, texture);
		glActiveTexture(Image::textureIndex[textureIndex]);
		//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);			//��ͼģʽΪ���
	}

public:
	static const int textureIndex[32];

private:

	int width, height, nrChannels;
	unsigned int texture;
};

