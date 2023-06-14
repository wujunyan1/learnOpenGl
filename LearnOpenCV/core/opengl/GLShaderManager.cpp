#include "GLShaderManager.h"

#include "../file/FilePathManager.h"

namespace Render
{
    GLShaderManager* GLShaderManager::ms_pSingleton_impl = NULL;

    unsigned int GLShaderManager::LoadVertexShader(std::string path)
    {
        // 1. ���ļ�·���л�ȡ����/Ƭ����ɫ��
        std::string vertexCode;
        std::ifstream vShaderFile;
        // ��֤ifstream��������׳��쳣��
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            std::string s = std::string(FilePathManager::getRootPath());
            // ���ļ�
            vShaderFile.open((s + std::string(path)).c_str());
            std::stringstream vShaderStream;
            // ��ȡ�ļ��Ļ������ݵ���������
            vShaderStream << vShaderFile.rdbuf();
            // �ر��ļ�������
            vShaderFile.close();
            // ת����������string
            vertexCode = vShaderStream.str();
        }
        catch (std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
            printf(e.what());
        }
        const char* vShaderCode = vertexCode.c_str();

        // 2. ������ɫ��
        unsigned int vertex;
        int success;
        char infoLog[512];

        // ������ɫ��
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        // ��ӡ�����������еĻ���
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

            return 0;
        };

        return vertex;
    }

    unsigned int GLShaderManager::LoadFragmentShader(std::string path)
    {
        // 1. ���ļ�·���л�ȡ����/Ƭ����ɫ��
        std::string fragmentCode;
        std::ifstream fShaderFile;
        // ��֤ifstream��������׳��쳣��
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            std::string s = std::string(FilePathManager::getRootPath());
            // ���ļ�

            fShaderFile.open((s + std::string(path)).c_str());
            std::stringstream fShaderStream;
            // ��ȡ�ļ��Ļ������ݵ���������
            fShaderStream << fShaderFile.rdbuf();
            // �ر��ļ�������
            fShaderFile.close();
            // ת����������string
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
            printf(e.what());
        }
        const char* fShaderCode = fragmentCode.c_str();


        // 2. ������ɫ��
        unsigned int fragment;
        int success;
        char infoLog[512];

        // ƬԴ��ɫ��
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);

        // ��ӡ�����������еĻ���
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        };

        return fragment;
    }

	unsigned int GLShaderManager::GetVertex(std::string path)
	{
		return LoadVertexShader(path);
	}

	unsigned int GLShaderManager::GetFragment(std::string path)
	{
        return LoadFragmentShader(path);
	}

	unsigned int GLShaderManager::GetShader(std::string name)
	{
        auto it = shader_ids->find(name);
        if (it == shader_ids->end())
        {
            return 0;
        }
        else
        {
            GLShader* shader = it->second;
            return shader->getID();
        }
	}

	unsigned int GLShaderManager::GetShader(std::string name, std::string vs, std::string fs)
	{
        auto it = shader_ids->find(name);
        if (it == shader_ids->end())
        {
            unsigned v = GetVertex(vs);
            unsigned f = GetFragment(fs);

            GLShader* shader = new GLShader(v, f);
            shader_ids->insert(std::pair<std::string, GLShader*>(name, shader));

            glDeleteShader(v);
            glDeleteShader(f);

            return shader->getID();
        }
        else
        {
            GLShader* shader = it->second;
            return shader->getID();
        }
	}


    GLShader* GLShaderManager::GetShaderObj(std::string name)
    {
        auto it = shader_ids->find(name);
        if (it == shader_ids->end())
        {
            return NULL;
        }
        else
        {
            return it->second;
        }
    }
}