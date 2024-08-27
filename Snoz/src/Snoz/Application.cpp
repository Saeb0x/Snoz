#include "szPCH.h"
#include "Application.h"

namespace Snoz
{

	Application::Application() :
		m_IsRunning(true)
	{
		
	}

	void Application::Run()
	{
		while (m_IsRunning);
	}
}
