#pragma once
#include "Log.h"

#ifdef SZ_PLATFORM_WINDOWS

extern Snoz::Application* Snoz::CreateApp();

int main(int argc, char* argv[])
{
	Snoz::Log::Init(); SZ_INFO("Loggers are initialized!");

	auto app = Snoz::CreateApp();
	app->Run();
	delete app;
}

#endif
