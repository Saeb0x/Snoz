#include "szPCH.h"
#include "Input.h"

#include "Log.h"

namespace Snoz
{
	std::array<bool, MAX_KEYS> Input::m_Keys = { false };
	std::array<bool, MAX_MOUSE_BUTTONS> Input::m_MouseButtons = { false };
	double Input::m_MouseX = 0.0;
	double Input::m_MouseY = 0.0;
	double Input::m_ScrollY = 0.0;

	bool Input::IsKeyDown(int keycode)
	{
		if(keycode >= MAX_KEYS)
		{
			SZ_WARN("The keycode {0} exceeds the max keys defined", keycode);
			return false;
		}

		return m_Keys[keycode];
	}

	bool Input::IsMouseButtonDown(int mouseButton)
	{
		if(mouseButton >= MAX_MOUSE_BUTTONS)
		{
			SZ_WARN("The mouse button {0} exceeds the max mouse buttons defined", mouseButton);
			return false;
		}

		return m_MouseButtons[mouseButton];
	}
}
