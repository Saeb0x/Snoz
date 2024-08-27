#include "szPCH.h"
#include "Application.h"

namespace Snoz
{
	Application::Application()
	{
		m_Window = std::make_unique<Window>(Window());
	}

	void Application::Run()
	{
		m_Window->Init();
		while (!m_Window->Closed())
		{
			m_Window->Clear();

			// Render here

			m_Window->Update();
		}
	}
}
