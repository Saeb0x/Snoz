#pragma once

#include "Core.h"
#include "Window.h"
#include "ImGuiLayer.h"
#include "LayerStack.h"
#include "Snoz/Platform/OpenGL/Shader.h"
#include "Snoz/Platform/OpenGL/VertexArray.h"

#include <memory>

namespace Snoz
{
	class SZ_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		virtual void Run();

		virtual void PushLayer(Layer* layer);
		virtual void PushOverlay(Layer* overlay);
		virtual void PopLayer(Layer* layer);
		virtual void PopOverlay(Layer* overlay);

		static Application* GetInstance() { return s_Instance; }
		Window& GetWindow() { return *m_Window; }
	protected:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;

		static Application* s_Instance;

		std::unique_ptr<VertexArray> m_VertexArray;
		std::unique_ptr<Shader> m_ShaderProg;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<VertexBufferLayout> m_BufferLayout;
	};

	// To be defined in EXTERNAL APP
	Application* CreateApp();
}

