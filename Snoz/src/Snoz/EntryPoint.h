#pragma once

#ifdef SZ_PLATFORM_WINDOWS

extern Snoz::Application* Snoz::CreateApp();

int main(int argc, char* argv[])
{
	auto app = Snoz::CreateApp();
	app->Run();
	delete app;
}

#endif
