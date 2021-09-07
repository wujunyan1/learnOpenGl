#pragma once

#include <vector>
#include "Component.h"

namespace Core {
	class Object
	{
	public:
		Object() {
			componentList = new std::vector<Component*>();
			children = NULL;
		}

		~Object() {
			for (auto i : *componentList)
			{
				i->onDestroy();
				delete i;
			}
			delete componentList;
		}

		template <typename T = Component>
		T* AddComponent()
		{
			T* t = new T();
			componentList->push_back(t);
			return t;
		}

		void AddChild(Object* child) {
			if (children == NULL) {
				children = new std::vector<Object*>();
			}
			children->push_back(child);
		}

		std::vector<Object*>* getChildren() {
			return children;
		}

	private:
		std::vector<Component*>* componentList;
		std::vector<Object*>* children;
	};


}