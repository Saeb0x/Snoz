#pragma once

#include "Core.h"

#include <string>

namespace Snoz
{
	class SZ_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate();
		virtual void OnImGuiRender();
	private:
		std::string m_Name;
	};
}