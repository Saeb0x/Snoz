#include "szPCH.h"
#include "OpenGLContext.h"
#include "Snoz/Log.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Snoz
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SZ_ASSERT(status, "GLAD initialization failed");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
