#pragma once
#include "Core.h"
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

namespace Core 
{
	class Transform :public Component
	{
	public:

		Transform() {
			position = Vector3();
			scale = Vector3(1.0f, 1.0f, 1.0f);
			rotate = Vector3();

			localMat4 = glm::mat4(1.0f);
			worldMat4 = glm::mat4(1.0f);



			matChanged = false;

			children = NULL;
		}

		void SetPosition(Vector3 v) {
			position = v;
			matChanged = true;
		}

		void SetScale(Vector3 v) {
			scale = v;
			matChanged = true;
		}

		void SetRotate(Vector3 v) {
			rotate = v;

			matChanged = true;
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

	private:

		void UpdateLocalMat4() {
			localMat4 = Mat4(1.0f);
			localMat4 = glm::translate(localMat4, glm::vec3(position.x, position.y, position.z));
			localMat4 = glm::rotate(localMat4, rotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
			localMat4 = glm::rotate(localMat4, rotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
			localMat4 = glm::rotate(localMat4, rotate.z, glm::vec3(0.0f, 0.0f, 1.0f));

			localMat4 = glm::scale(localMat4, glm::vec3(scale.x, scale.y, scale.z));

			forword = localMat4 * Vector4(0, 0, 1, 0);
			right = localMat4 * Vector4(1, 0, 0, 0);
			up = localMat4 * Vector4(0, 1, 0, 0);
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

		bool matChanged = false;

		std::vector<Transform*>* children;
	};


}
