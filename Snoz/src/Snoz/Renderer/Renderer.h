#pragma once

namespace Snoz
{
	enum class RendererAPI
	{
		None = 0,
		OpenGL = 1
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetCurrentAPI() { return m_CurrentAPI; }
	private:
		static RendererAPI m_CurrentAPI;
	};
}
