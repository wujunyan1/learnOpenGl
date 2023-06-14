#pragma once
#include "Core.h"
#include "Component.h"
#include "../math/Math.h"
#include "../render/RenderMain.h"
#include "../meshModel/AModel.h"
#include "../render/BlendFunc.h"
#include "RenderInterface.h"

namespace Core
{
	class Model : public GameComponent, public RenderInterface
	{
	public:
		Model();
		~Model();

		void setModel(AModel* model);
		

		void bindRender();

		virtual void Render();

		void setShader(std::string shaderName);

		void setRenderQueue(std::string renderName);

		void setRenderStageIndex(unsigned int stage);

		// �Ƿ������ģʽ
		void setBlend(bool enable);

		// Ŀ������Ȼ�����ģ� src��ps�����
		void setBlendFunc(Render::BlendFunc src, Render::BlendFunc target);

		// �Ƿ�����Ȳ��ԣ�Ĭ�Ͽ���
		void setDepthTest(bool enable);
	private:
		// ����
		Render::RenderProgram* renderProgram = NULL;

		bool b_isShow = true;

		float f_alpha = 1.0f;

	private:
	};
}
