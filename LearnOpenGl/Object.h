#pragma once

#include <vector>
#include "Component.h"
#include "Core.h"

namespace Core {
	class Object
	{
	public:
		Object() {
			componentList = new std::vector<Component*>();
		}

		~Object() {
			for (auto i : *componentList)
			{
				i->OnDestroy();
				delete i;
			}
			delete componentList;
		}

		template <typename T = Component>
		T* AddComponent()
		{
			T* t = new T();
			componentList->push_back(t);
			t->setObject(this);
			t->Bind();
			return t;
		}

		void RemoveComponent(Component * component)
		{
			std::vector<Component*>::iterator it;
			for (it = componentList->begin(); it != componentList->end();)
			{
				auto i = *it;
				if (i == component) {
					i->UnBind();
					i->OnDestroy();
					componentList->erase(it);
					delete i;
					return;
				}
			}
		}

		template <typename T = Component>
		T* GetComponent()
		{
			for (auto i : *componentList)
			{
				if (dynamic_cast<T*>(&i) != nullptr) {
					return i;
				}
			}
			return nullptr;
		}

	private:
		std::vector<Component*>* componentList;
		String name;
	};


}