#pragma once

#include "Core.h"
#include "ImGuiLayer.h"

#include <string>
#include <memory>

namespace Snoz
{
	struct WindowProps
	{
		std::string m_Title;
		unsigned int m_Width;
		unsigned int m_Height;
		bool b_IsVSync;

		WindowProps(const std::string& title = "Snoz Rendering Engine", unsigned int width = 1280, unsigned int height = 720, bool enableVSync = true)
			: m_Title(title), m_Width(width), m_Height(height), b_IsVSync(enableVSync)
		{
		}
	};

	class SZ_API Window
	{
	public:
		Window(const WindowProps& windowProperties = WindowProps());
		~Window();

		void Init();
		bool Closed();
		void Clear();
		void Update();
		void Terminate();

		inline std::string GetTitle() const { return m_WindowProps.m_Title; }
		inline unsigned int GetWidth() const { return m_WindowProps.m_Width; }
		inline unsigned int GetHeight() const { return m_WindowProps.m_Height; }
		inline bool IsVSync() const { return m_WindowProps.b_IsVSync; }

		inline ImGuiLayer& GetImGuiLayer() { return *m_ImGuiLayer; }

		void SetVSync(bool enabled);
	private:
		void Cleanup();
	private:
		GLFWwindow* m_Window;
		WindowProps m_WindowProps;
		std::shared_ptr<ImGuiLayer> m_ImGuiLayer;
	};
}

