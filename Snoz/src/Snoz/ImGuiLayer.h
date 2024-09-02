#pragma once

#include "Core.h"
#include "Layer.h"

struct GLFWwindow;

namespace Snoz
{
	class SZ_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAttach() override;
		void OnDetach() override;

		void OnImGuiRender() override;

		void Begin();
		void End();
	};

}
