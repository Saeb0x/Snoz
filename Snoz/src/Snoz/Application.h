#pragma once

#include "Core.h"

namespace Snoz
{
	class SZ_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();
	private:
		bool m_IsRunning;
	};

	// To be defined in EXTERNAL APP
	Application* CreateApp();
}

