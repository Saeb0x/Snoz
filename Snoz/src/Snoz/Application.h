#pragma once

#include "Core.h"
#include "Window.h"

#include <memory>

namespace Snoz
{
	class SZ_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		virtual void Run();
	private:
		std::unique_ptr<Window> m_Window;
	};

	// To be defined in EXTERNAL APP
	Application* CreateApp();
}

