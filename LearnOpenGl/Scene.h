#pragma once
#include "Object.h"
#include "Transform.h"

namespace Core
{
	class Scene : public Object
	{
	public:
		Scene() {
			Transform* transform = AddComponent<Transform>();
			transform->SetPosition(Vector3(0, 0, 0));
			transform->SetRotate(Vector3(0, 0, 0));
			transform->SetScale(Vector3(1, 1, 1));
		}
	};
}

