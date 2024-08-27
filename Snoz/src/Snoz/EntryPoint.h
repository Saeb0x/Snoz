#pragma once
#include "Log.h"

#ifdef SZ_PLATFORM_WINDOWS

extern Snoz::Application* Snoz::CreateApp();

int main(int argc, char* argv[])
{
	Snoz::Log::Init();

	SZ_INFO("Ready to go!");
	SZ_APP_INFO("Hi!");

	auto app = Snoz::CreateApp();
	app->Run();
	delete app;
}

#endif
