#include "szPCH.h"
#include "Application.h"

#include "Input.h"
#include "Log.h"

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
