#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "OpenGLCore.h"
#include "../math/Math.h"

class GLShader
{
public:

    // ��������ȡ��������ɫ��
    GLShader(unsigned int vertex, unsigned int  fragment);
    ~GLShader();

    // ʹ��/�������
    void use();
    // uniform���ߺ���
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setFloat4(const std::string& name, float r, float g, float b, float a) const;
    void setVec2(const std::string& name, Math::Vector2 value) const;
    void setVec3(const std::string& name, Math::Vector3 value) const;
    void setVec3(const std::string& name, float x, float y, float z) const;
    void setMat4(const std::string& name, Math::Matrix4 mat) const;
    void setTexture(const std::string& name, unsigned int index) const;

    void setBool(const std::string& name, const void* value) const;
    void setInt(const std::string& name, const void* value) const;
    void setFloat(const std::string& name, const void* value) const;
    void setFloat4(const std::string& name, const void* value) const;
    void setVec3(const std::string& name, const void* value) const;
    void setMat4(const std::string& name, const void* mat) const;

    unsigned int getID() { return ID; };
public:
    // ����ID
    unsigned int ID;

    unsigned int vs;
    unsigned int fs;
};