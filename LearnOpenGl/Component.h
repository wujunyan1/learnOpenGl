#pragma once

namespace Core 
{
	class Object;

	class Component
	{
	public:
		virtual void Init();
		virtual void OnDestroy();

		virtual void Bind(){}
		virtual void UnBind() {}
		virtual void PreUpdate() {}
		virtual void Update() {}
		virtual void LaterUpdate() {}

		void setObject(Object* o);

		Object* getObject();
	protected:
		Object* object = nullptr;
	};
}

