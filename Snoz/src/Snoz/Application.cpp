#include "szPCH.h"
#include "Application.h"

#include "Input.h"
#include "Log.h"

#include <glad/glad.h>

namespace Snoz
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;
		m_Window = std::make_unique<Window>(Window());
		m_Window->Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		// Vertex Array
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		// Vertex Buffer
		glGenBuffers(1, &m_VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

		float vertices[3 * 3] =
		{
			-0.5f, 0.0f, 0.0f,
			0.0f, 0.5f, 0.0f,
			0.5f, 0.0f, 0.0f
		};
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		// Index Buffer
		glGenBuffers(1, &m_IndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

		float indices[3] =
		{
			0, 1, 2
		};
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}

	void Application::Run()
	{
		glClearColor(0.5f, 0.6f, 0.7f, 1.0f);
		while (!m_Window->Closed())
		{
			// Render here
			m_Window->Clear();

			if (Snoz::Input::IsKeyDown(SZ_KEY_ESCAPE))
			{
				SZ_WARN("Key Escape is pressed");
				m_Window->Terminate();
			}

			/*if (Snoz::Input::IsCursorIn())
				SZ_TRACE("Mouse Coord: {0}, {1}", Snoz::Input::GetMousePosX(), Snoz::Input::GetMousePosY());*/

			for (Layer* layer : m_LayerStack.GetLayers())
			{
				layer->OnUpdate();
			}

			m_ImGuiLayer->Begin();
			m_ImGuiLayer->OnImGuiRender();
			m_ImGuiLayer->End();

			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			m_Window->Update();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
		layer->OnDetach();
	}

	void Application::PopOverlay(Layer* overlay)
	{
		m_LayerStack.PopOverlay(overlay);
		overlay->OnDetach();
	}
}
