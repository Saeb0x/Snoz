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
}
