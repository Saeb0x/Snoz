#include "szPCH.h"
#include "Application.h"

#include "Input.h"
#include "Log.h"

// TEMP
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}

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
	}

	void Application::Run()
	{
		while (!m_Window->Closed())
		{
			// Render here
			m_Window->Clear();

			if (Snoz::Input::IsKeyDown(SZ_KEY_ESCAPE))
			{
				SZ_WARN("Key Escape is pressed");
				m_Window->Terminate();
			}
			if (Snoz::Input::IsCursorIn())
				SZ_TRACE("Mouse Coord: {0}, {1}", Snoz::Input::GetMousePosX(), Snoz::Input::GetMousePosY());

			for (Layer* layer : m_LayerStack.GetLayers())
			{
				layer->OnUpdate();
			}

			m_ImGuiLayer->Begin();
			m_ImGuiLayer->OnImGuiRender();
			m_ImGuiLayer->End();

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
