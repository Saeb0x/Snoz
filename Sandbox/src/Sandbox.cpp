#include <Snoz.h>

class Sandbox : public Snoz::Application
{
public:
	Sandbox() = default;
	~Sandbox() override = default;

	void Run() override;
};

void Sandbox::Run()
{
	m_Window->Init();
	while (!m_Window->Closed())
	{
		m_Window->Clear();

		if (Snoz::Input::IsKeyDown(SZ_KEY_ESCAPE))
		{
			SZ_WARN("Key Escape is pressed");
			m_Window->Terminate();
		}

		if(Snoz::Input::IsCursorIn())
			SZ_TRACE("Mouse Coord: {0}, {1}", Snoz::Input::GetMousePosX(), Snoz::Input::GetMousePosY());

		// Render here

		m_Window->Update();
	}
}

Snoz::Application* Snoz::CreateApp()
{
	return new Sandbox;
}
