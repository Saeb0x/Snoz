#include "szPCH.h"
#include "Window.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace Snoz
{
	static void error_callback(int error_code, const char* description)
	{
		SZ_ERROR("GLFW error {0}: {1}", error_code, description);
	}

	Window::Window(const WindowProps& windowProperties) : m_WindowProps(windowProperties)
	{
	}

	Window::~Window()
	{
		Cleanup();
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	void Window::Init()
	{
		if (!glfwInit())
		{
			SZ_ERROR("Failure in initializing GLFW");
			return;
		}

		m_Window = glfwCreateWindow((int)m_WindowProps.m_Width, (int)m_WindowProps.m_Height, m_WindowProps.m_Title.c_str(), nullptr, nullptr);

		if(!m_Window)
		{
			SZ_ERROR("Failure in creating window \"{0}\"", m_WindowProps.m_Title);
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_Window);

		if (m_WindowProps.b_IsVSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		// GLFW callbacks
		glfwSetErrorCallback(error_callback);

		glClearColor(0.5f, 0.6f, 0.7f, 1.0f);

		SZ_INFO("Window is successfully initialized and created");
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Window::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	bool Window::Closed()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Cleanup()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}
}
