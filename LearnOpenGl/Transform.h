#pragma once
#include "Core.h"
#include "Component.h"
#include "Object.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

namespace Core 
{
	class Transform : public Component
	{
	public:

		Transform() {
			position = Vector3();
			scale = Vector3(1.0f, 1.0f, 1.0f);
			rotate = Vector3(1.0f, 1.0f, 1.0f);

			localMat4 = Mat4(1.0f);
			worldMat4 = Mat4(1.0f);
			rotateMat = Mat4(1.0f);


			matChanged = false;

			children = NULL;
		}

		Vector3 GetPosition() {
			return Vector3(position.x, position.y, position.z);
		}

		void SetPosition(Vector3 v) {
			position = v;
			matChanged = true;
		}

		void SetScale(Vector3 v) {
			scale = v;
			matChanged = true;
		}

		void SetRotate(Vector3 rotate) {
			rotateMat = Mat4(1.0f);
			rotateMat = glm::rotate(rotateMat, rotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
			rotateMat = glm::rotate(rotateMat, rotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
			rotateMat = glm::rotate(rotateMat, rotate.z, glm::vec3(0.0f, 0.0f, 1.0f));

			this->rotate = rotate;
			matChanged = true;
		}

		Vector3 GetRotate() {
			return rotate;
		}

		void Quaternion() {

		}

		glm::mat4 GetLocalMat4() {
			if (matChanged) {
				UpdateLocalMat4();
			}
			return localMat4;
		}

		glm::mat4 GetWorldMat4() {
			if (matChanged) {
				UpdateLocalMat4();
			}
			return worldMat4;
		}

		void AddChild(Transform* child) {
			if (children == NULL) {
				children = new std::vector<Transform*>();
			}
			children->push_back(child);
		}

		Transform* GetChildByIndex(int index) {
			return children->at(index);
		}

		std::vector<Transform*>* getChildren() {
			return children;
		}

		Vector3 getForword() {
			if (matChanged) {
				UpdateLocalMat4();
			}
			return forword;
		}

		Vector3 getRight() {
			if (matChanged) {
				UpdateLocalMat4();
			}
			return right;
		}

		Vector3 getUp() {
			if (matChanged) {
				UpdateLocalMat4();
			}
			return up;
		}


		void PreUpdate() {
			if (children == nullptr) {
				return;
			}
			for (auto i : *children)
			{
				i->getObject()->PreUpdate();
			}
		}
		void Update() {
			if (children == nullptr) {
				return;
			}
			for (auto i : *children)
			{
				i->getObject()->Update();
			}
		}
		void LaterUpdate() {
			if (children == nullptr) {
				return;
			}
			for (auto i : *children)
			{
				i->getObject()->LaterUpdate();
			}
		}

	private:

		void UpdateLocalMat4() {
			localMat4 = Mat4(1.0f);
			localMat4 = glm::translate(localMat4, position);
			localMat4 = localMat4 * rotateMat;

			localMat4 = glm::scale(localMat4, glm::vec3(scale.x, scale.y, scale.z));

			forword = localMat4 * Vector4(0, 0, 1, 0);
			right = localMat4 * Vector4(1, 0, 0, 0);
			up = localMat4 * Vector4(0, 1, 0, 0);

			matChanged = false;
		}

	private:
		Vector3 position = Vector3();
		Vector3 scale = Vector3();
		Vector3 rotate = Vector3();

		Vector3 forword = Vector3();
		Vector3 right = Vector3();
		Vector3 up = Vector3();

		Mat4 localMat4 = Mat4();
		Mat4 worldMat4 = Mat4();

		Mat4 rotateMat = Mat4();

		bool matChanged = false;

		std::vector<Transform*>* children;
	};


}
