﻿#include "szPCH.h"
#include "Window.h"

#include "Log.h"
#include "Input.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

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

		m_Window = glfwCreateWindow((int)m_WindowProps.m_Width, (int)m_WindowProps.m_Height, m_WindowProps.m_Title.c_str(), nullptr, nullptr);

		if (!m_Window)
		{
			SZ_ERROR("Failure in creating window \"{0}\"", m_WindowProps.m_Title);
			glfwTerminate();
			return;
		}
		SZ_INFO("Window is successfully initialized and created");

		m_GraphicsContext = new OpenGLContext(m_Window);
		m_GraphicsContext->Init();

		glfwSetWindowUserPointer(m_Window, this);

		if (m_WindowProps.b_IsVSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

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

		glfwSetCursorEnterCallback(m_Window, [](GLFWwindow* window, int entered)
			{
				if (entered)
					Input::m_CursorIn = true;
				else
				{
					Input::m_CursorIn = false;
				}
			}
		);

		glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				glViewport(0, 0, width, height);
			}
		);
	}

	void Window::Update()
	{
		m_GraphicsContext->SwapBuffers();
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
