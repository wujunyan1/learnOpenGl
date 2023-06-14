#pragma once

#include <map>
#include "../math/Math.h"
#include "ShaderProgram.h"
#include "../file/Image.h"
#include "Texture.h"
#include "../opengl/OpenGLCore.h"
#include "../opengl/GLShader.h"
#include "../render/Material.h"
#include "RenderBaseMesh.h"

namespace Render
{
	/*
		mesh ���ݣ���Ӧһ��vbo
		���㣬uv��������ͼ �ȵ�
	*/
	class RenderFontMesh : public RenderBaseMesh
	{
	public:
		RenderFontMesh(std::string name);
	
		virtual void Render(Render::ShaderProgram* program, Render::Material* material);
	private:

	};


}