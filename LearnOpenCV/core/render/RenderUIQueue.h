#pragma once

#include <map>
#include "../math/Math.h"
#include "RenderQueue.h"

namespace UI {
	class UICanvas;
}

namespace Render
{
	class RenderUIQueue: public Render::RenderQueue
	{
	public:
		RenderUIQueue();

		~RenderUIQueue();

		virtual void Render(Core::Camera* camera);

		void addRenderCanvas(UI::UICanvas* canvas);

		virtual void clear();

	private:

		// �������Ҫ��Ⱦ��
		std::vector<UI::UICanvas*>* activeRenderUI;

		Math::Matrix4 ortho;
	};


}