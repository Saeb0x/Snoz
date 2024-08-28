#include "szPCH.h"
#include "Application.h"

#include "Input.h"
#include "Log.h"

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

			if (Input::IsKeyDown(SZ_KEY_ESCAPE))
			{
				SZ_TRACE("Key Escape is pressed");
			}

			SZ_TRACE("Mouse Coord: {0}, {1}", Input::GetMousePosX(), Input::GetMousePosY());
			SZ_TRACE("Mouse Scroll (vertical): {0}", Input::GetScrollY());

			// Render here

			m_Window->Update();
		}
	}
}
