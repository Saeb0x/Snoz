#include "szPCH.h"
#include "Application.h"

#include "Input.h"
#include "Log.h"

#include <glad/glad.h>

namespace Snoz
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;
		m_Window = std::make_unique<Window>(Window());
		m_Window->Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		// Vertex Array
		m_VertexArray = std::make_unique<VertexArray>(VertexArray());

		float vertices[5 * 3] =
		{
			// VA1: Coords		// VA2: Color
			-0.5f, -0.5f,		1.0f, 0.0f, 0.0f,
			 0.0f,  0.5f,		0.0f, 1.0f, 0.0f,
			 0.5f, -0.5f,		0.0f, 0.0f, 1.0f
		};
		m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		// Vertex Buffer Layout
		m_BufferLayout = std::make_unique<VertexBufferLayout>(VertexBufferLayout());
		m_BufferLayout->Push<float>(2);
		m_BufferLayout->Push<float>(3);

		// Binding each vertex buffer with its layout
		m_VertexArray->AddBuffer(*m_VertexBuffer, *m_BufferLayout);

		unsigned int indices[3] =
		{
			0, 1, 2
		};
		m_IndexBuffer.reset(IndexBuffer::Create(indices, 3));

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec3 a_Color;

			out vec3 v_Color;
			
			void main()
			{
				v_Color = a_Color;
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			in vec3 v_Color;
			out vec4 color;

			void main()
			{
				color = vec4(v_Color,1.0);
			}
		)";

		m_ShaderProg.reset(new Shader(vertexSrc, fragmentSrc));
	}

	void Application::Run()
	{
		glClearColor(0.5f, 0.6f, 0.7f, 1.0f);
		while (!m_Window->Closed())
		{
			// Render here
			m_Window->Clear();

			m_ShaderProg->Bind();
			m_VertexArray->Bind();
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack.GetLayers())
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			if (Snoz::Input::IsKeyDown(SZ_KEY_ESCAPE))
			{
				SZ_WARN("Key Escape is pressed");
				m_Window->Terminate();
			}

			/*if (Snoz::Input::IsCursorIn())
				SZ_TRACE("Mouse Coord: {0}, {1}", Snoz::Input::GetMousePosX(), Snoz::Input::GetMousePosY());*/

			for (Layer* layer : m_LayerStack.GetLayers())
			{
				layer->OnUpdate();
			}

			m_Window->Update();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
		layer->OnDetach();
	}

	void Application::PopOverlay(Layer* overlay)
	{
		m_LayerStack.PopOverlay(overlay);
		overlay->OnDetach();
	}
}
