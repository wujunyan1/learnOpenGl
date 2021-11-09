#pragma once
#include "Component.h"
#include "Core.h"
#include "Shader.h"
#include "Image.h"
#include "RenderMesh.h"
#include "Transform.h"

#include <type_traits>

namespace Core
{
	class Mesh : public Component
	{


	public:
		virtual void Bind();

		template<size_t N>
		void SetVertices(const Vector3(&verts)[N]) // Vector3 verts[]
		{
			int length = N;
			verticesNum = length;

			unsigned int index = 0;
			if (vertices != nullptr) {
				delete vertices;
			}
			vertices = new float[length * 3];

			for (int i = 0; i < length; i++)
			{
				Vector3 v = verts[i];
				int index = i * 3;
				vertices[index] = v.x;
				vertices[index + 1] = v.y;
				vertices[index + 2] = v.z;

				printf("%f %f %f ", vertices[index], vertices[index + 1], vertices[index + 2]);
			}
		}

		template<size_t N>
		void SetUVs(const Vector2(&uvs)[N])
		{
			int length = N;

			unsigned int index = 0;
			if (UVs != nullptr) {
				delete UVs;
			}
			UVs = new float[length * 2];

			for (int i = 0; i < length; i++)
			{
				Vector2 v = uvs[i];
				int index = i * 2;
				UVs[index] = v.x;
				UVs[index + 1] = v.y;
			}
		}

		void SetIndices(unsigned int indices[])
		{
			this->indices = indices;
		}

		void SetShader(Shader* shader)
		{
			this->shader = shader;
		}

		void SetImage(Image* image)
		{
			this->image = image;
		}

		void bindRender();
		virtual void Render();

	private:
		unsigned int VAO;
		unsigned int VBO;
		unsigned int EBO;

		Transform* shaderTransform;

	public:
		float* vertices = nullptr;
		float* UVs = nullptr;
		unsigned int* indices = nullptr;
		float* vs = nullptr;

		int verticesNum = 0;

		Shader* shader;
		Image* image;

		RenderMesh* renderMesh;
	};
}

