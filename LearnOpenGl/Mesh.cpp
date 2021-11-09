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
	glGenBuffers(1, &EBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(verticesNum * sizeof(float)));
	glEnableVertexAttribArray(1);

	vs = new float[verticesNum * 5];

	memcpy(vs, vertices, sizeof(vertices));
	memcpy(vs, UVs, sizeof(UVs));
}

void Mesh::Render() {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBindVertexArray(VAO);

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


	glBufferData(GL_ARRAY_BUFFER, sizeof(vs), vs, GL_STREAM_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glDrawArrays(GL_TRIANGLES, 0, verticesNum);
	image->use();
}