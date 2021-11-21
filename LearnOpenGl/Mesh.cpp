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

	int n = verticesNum * 8;
	vs = new float[n];

	//memcpy(vs, vertices, n * sizeof(vertices[0]));
	////vs = vs + (verticesNum * 3);
	//int m = verticesNum * 2 * sizeof(UVs[0]);
	//memcpy(vs + n, UVs, m);


	for (int i = 0; i < verticesNum; i++)
	{
		int index = i * 8;
		int vIndex = i * 3;
		int uIndex = i * 2;
		int nIndex = i * 3;

		vs[index] = vertices[vIndex];
		vs[index + 1] = vertices[vIndex + 1];
		vs[index + 2] = vertices[vIndex + 2];
		vs[index + 3] = UVs[uIndex];
		vs[index + 4] = UVs[uIndex + 1];
		vs[index + 5] = normals[nIndex];
		vs[index + 6] = normals[nIndex + 1];
		vs[index + 7] = normals[nIndex + 2];

		printf("%f \n", vs[i]);
	}

	printf("%d %d \n", VAO, VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, n * sizeof(float), vs, GL_STATIC_DRAW);

	glBindVertexArray(VAO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(3);
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
	Transform* cameraTransform = camera.getObject()->GetComponent<Transform>();

	Logic::PointLight pointLight = scene->getPointLight();
	Transform * pointTransform = pointLight.getObject()->GetComponent<Transform>();

	shader->use();
	shader->setFloat4("ourColor", 0.0f, 0.0f, 0.0f, 1.0f);
	shader->setInt("ourTexture", 0);
	shader->setMat4("view", view);
	shader->setMat4("projection", projection);
	shader->setMat4("model", shaderTransform->GetLocalToWorldMat4());
	shader->setMat4("modelInverse", shaderTransform->GetLocalToWorldInverseMat4());
	shader->setVec3("lightColor", pointLight.lightColor);  //  Vector3(1.0f, 1.0f, 1.0f)
	shader->setVec3("lightPos", pointTransform->GetPosition()); //  Vector3(0.0f, 2.0f, 0.0f)
	shader->setVec3("viewPos", cameraTransform->GetPosition());


	//glBufferData(GL_ARRAY_BUFFER, sizeof(vs), vs, GL_STREAM_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//printf("verticesNum  %d \n", verticesNum);
	image->use();


	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, verticesNum);
	glBindVertexArray(0);
}