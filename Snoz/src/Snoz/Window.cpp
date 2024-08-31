#include "szPCH.h"
#include "Window.h"

#include <complex.h>

#include "Log.h"
#include "Input.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h> 

namespace Snoz
{
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

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		m_Window = glfwCreateWindow((int)m_WindowProps.m_Width, (int)m_WindowProps.m_Height, m_WindowProps.m_Title.c_str(), nullptr, nullptr);

		if (!m_Window)
		{
			SZ_ERROR("Failure in creating window \"{0}\"", m_WindowProps.m_Title);
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);

		if (m_WindowProps.b_IsVSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		// GLFW callbacks
		glfwSetErrorCallback([](int error_code, const char* description)
			{
				SZ_ERROR("GLFW error {0}: {1}", error_code, description);
			}
		);

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				Input::m_Keys[key] = action != GLFW_RELEASE;
			}
		);

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				Input::m_MouseButtons[button] = action != GLFW_RELEASE;
			}
		);

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				Input::m_MouseX = xpos;
				Input::m_MouseY = ypos;
			}
		);

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				Input::m_ScrollY = yoffset;
			}
		);

		glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				glViewport(0, 0, width, height);
			}
		);

		glClearColor(0.5f, 0.6f, 0.7f, 1.0f);

		SZ_INFO("Window is successfully initialized and created");
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Window::Terminate()
	{
		glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
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
