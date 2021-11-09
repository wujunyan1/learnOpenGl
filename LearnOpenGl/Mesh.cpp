#include "Mesh.h"
#include "SceneManager.h"
#include "Scene.h"

using namespace Core;

void Mesh::Bind() {
	shaderTransform = object->GetComponent<Transform>();
}

void Mesh::bindRender() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	int n = verticesNum * 5;
	vs = new float[n];

	n = verticesNum * 3;
	//memcpy(vs, vertices, n * sizeof(vertices[0]));
	////vs = vs + (verticesNum * 3);
	//int m = verticesNum * 2 * sizeof(UVs[0]);
	//memcpy(vs + n, UVs, m);


	for (int i = 0; i < verticesNum; i++)
	{
		int index = i * 5;
		int vIndex = i * 3;
		int uIndex = i * 2;
		vs[index] = vertices[vIndex];
		vs[index + 1] = vertices[vIndex + 1];
		vs[index + 2] = vertices[vIndex + 2];
		vs[index + 3] = UVs[uIndex];
		vs[index + 4] = UVs[uIndex + 1];

		printf("%f \n", vs[i]);
	}

	printf("%d %d \n", VAO, VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, n * sizeof(float), vs, GL_STATIC_DRAW);

	glBindVertexArray(VAO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	printf("verticesNum  %d \n", verticesNum);
	n = verticesNum * 3 * sizeof(float);
	printf("verticesNum  %d \n", n);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Mesh::Render() {
	//glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vs), vs, GL_STREAM_DRAW);

	Scene* scene = SceneManager::GetInstance()->GetCurrScene();
	Camera camera = scene->getMainCamera();
	Mat4 view = camera.GetViewMatrix();
	Mat4 projection = camera.GetProjection();

	shader->use();
	shader->setFloat4("ourColor", 0.0f, 0.0f, 0.0f, 1.0f);
	shader->setInt("ourTexture", 0);
	shader->setMat4("view", view);
	shader->setMat4("projection", projection);
	shader->setMat4("model", shaderTransform->GetLocalMat4());


	//glBufferData(GL_ARRAY_BUFFER, sizeof(vs), vs, GL_STREAM_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//printf("verticesNum  %d \n", verticesNum);
	image->use();


	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, verticesNum);
	glBindVertexArray(0);
}