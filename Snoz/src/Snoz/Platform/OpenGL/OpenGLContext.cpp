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

		SZ_INFO("OpenGL Context Info:");
		SZ_INFO("	Vendor & Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		SZ_INFO("	Version: {0}", (const char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
