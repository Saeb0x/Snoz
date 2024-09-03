#pragma once

#include "Snoz/Renderer/Context.h"

struct GLFWwindow;

namespace Snoz
{
	class OpenGLContext : public Context
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);
		~OpenGLContext() = default;

		void Init() override;
		void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;
	};
}

