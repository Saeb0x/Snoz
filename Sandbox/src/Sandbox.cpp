#include <Snoz.h>

class Sandbox : public Snoz::Application
{
public:
	Sandbox() = default;
	~Sandbox() override = default;
};

Snoz::Application* Snoz::CreateApp()
{
	return new Sandbox;
}
