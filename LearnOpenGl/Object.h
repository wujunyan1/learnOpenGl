#pragma once

#include <vector>
#include "Component.h"
class Object
{
public:
	Object() {
		componentList = new std::vector<Component*>();
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

private:
	std::vector<Component*>* componentList;
};

