#include <Snoz.h>

// Temp
#include <gl/GL.h>

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

		glBegin(GL_TRIANGLES);
		glVertex2f(-1.0f, -1.0f);
		glVertex2f(1.0f, -1.0f);
		glVertex2f(0.0f, 1.0f);
		glEnd();

		if (Snoz::Input::IsKeyDown(SZ_KEY_ESCAPE))
		{
			SZ_TRACE("Key Escape is pressed");
		}

		SZ_TRACE("Mouse Coord: {0}, {1}", Snoz::Input::GetMousePosX(), Snoz::Input::GetMousePosY());

		// Render here

		m_Window->Update();
	}
}

Snoz::Application* Snoz::CreateApp()
{
	return new Sandbox;
}
