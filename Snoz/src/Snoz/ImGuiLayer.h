#pragma once

#include "Core.h"

struct GLFWwindow;

namespace Snoz
{
	class SZ_API ImGuiLayer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void Init(GLFWwindow* window);

		void StartFrame();
		void EndFrame();
	};

}
