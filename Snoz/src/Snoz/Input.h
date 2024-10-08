﻿#pragma once

#include "Core.h"

#include <array>
#include <utility>

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32 

namespace Snoz
{
	class SZ_API Input
	{
	public:
		Input();
		~Input() = default;

		static bool IsKeyDown(int keycode);
		static bool IsMouseButtonDown(int mouseButton);
		static bool IsCursorIn();

		inline static double GetMousePosX() { return m_MouseX; }
		inline static double GetMousePosY() { return m_MouseY; }

		inline static double GetScrollY() { return m_ScrollY; }

		friend class Window;
	private:
		static std::array<bool, MAX_KEYS> m_Keys;
		static std::array<bool, MAX_MOUSE_BUTTONS> m_MouseButtons;
		static double m_MouseX;
		static double m_MouseY;
		static double m_ScrollY;
		static bool m_CursorIn;
	};
}

// From glfw3.h
#define SZ_KEY_SPACE              32
#define SZ_KEY_APOSTROPHE         39  /* ' */
#define SZ_KEY_COMMA              44  /* , */
#define SZ_KEY_MINUS              45  /* - */
#define SZ_KEY_PERIOD             46  /* . */
#define SZ_KEY_SLASH              47  /* / */
#define SZ_KEY_0                  48
#define SZ_KEY_1                  49
#define SZ_KEY_2                  50
#define SZ_KEY_3                  51
#define SZ_KEY_4                  52
#define SZ_KEY_5                  53
#define SZ_KEY_6                  54
#define SZ_KEY_7                  55
#define SZ_KEY_8                  56
#define SZ_KEY_9                  57
#define SZ_KEY_SEMICOLON          59  /* ; */
#define SZ_KEY_EQUAL              61  /* = */
#define SZ_KEY_A                  65
#define SZ_KEY_B                  66
#define SZ_KEY_C                  67
#define SZ_KEY_D                  68
#define SZ_KEY_E                  69
#define SZ_KEY_F                  70
#define SZ_KEY_G                  71
#define SZ_KEY_H                  72
#define SZ_KEY_I                  73
#define SZ_KEY_J                  74
#define SZ_KEY_K                  75
#define SZ_KEY_L                  76
#define SZ_KEY_M                  77
#define SZ_KEY_N                  78
#define SZ_KEY_O                  79
#define SZ_KEY_P                  80
#define SZ_KEY_Q                  81
#define SZ_KEY_R                  82
#define SZ_KEY_S                  83
#define SZ_KEY_T                  84
#define SZ_KEY_U                  85
#define SZ_KEY_V                  86
#define SZ_KEY_W                  87
#define SZ_KEY_X                  88
#define SZ_KEY_Y                  89
#define SZ_KEY_Z                  90
#define SZ_KEY_LEFT_BRACKET       91  /* [ */
#define SZ_KEY_BACKSLASH          92  /* \ */
#define SZ_KEY_RIGHT_BRACKET      93  /* ] */
#define SZ_KEY_GRAVE_ACCENT       96  /* ` */
#define SZ_KEY_WORLD_1            161 /* non-US #1 */
#define SZ_KEY_WORLD_2            162 /* non-US #2 */
#define SZ_KEY_ESCAPE             256
#define SZ_KEY_ENTER              257
#define SZ_KEY_TAB                258
#define SZ_KEY_BACKSPACE          259
#define SZ_KEY_INSERT             260
#define SZ_KEY_DELETE             261
#define SZ_KEY_RIGHT              262
#define SZ_KEY_LEFT               263
#define SZ_KEY_DOWN               264
#define SZ_KEY_UP                 265
#define SZ_KEY_PAGE_UP            266
#define SZ_KEY_PAGE_DOWN          267
#define SZ_KEY_HOME               268
#define SZ_KEY_END                269
#define SZ_KEY_CAPS_LOCK          280
#define SZ_KEY_SCROLL_LOCK        281
#define SZ_KEY_NUM_LOCK           282
#define SZ_KEY_PRINT_SCREEN       283
#define SZ_KEY_PAUSE              284
#define SZ_KEY_F1                 290
#define SZ_KEY_F2                 291
#define SZ_KEY_F3                 292
#define SZ_KEY_F4                 293
#define SZ_KEY_F5                 294
#define SZ_KEY_F6                 295
#define SZ_KEY_F7                 296
#define SZ_KEY_F8                 297
#define SZ_KEY_F9                 298
#define SZ_KEY_F10                299
#define SZ_KEY_F11                300
#define SZ_KEY_F12                301
#define SZ_KEY_F13                302
#define SZ_KEY_F14                303
#define SZ_KEY_F15                304
#define SZ_KEY_F16                305
#define SZ_KEY_F17                306
#define SZ_KEY_F18                307
#define SZ_KEY_F19                308
#define SZ_KEY_F20                309
#define SZ_KEY_F21                310
#define SZ_KEY_F22                311
#define SZ_KEY_F23                312
#define SZ_KEY_F24                313
#define SZ_KEY_F25                314
#define SZ_KEY_KP_0               320
#define SZ_KEY_KP_1               321
#define SZ_KEY_KP_2               322
#define SZ_KEY_KP_3               323
#define SZ_KEY_KP_4               324
#define SZ_KEY_KP_5               325
#define SZ_KEY_KP_6               326
#define SZ_KEY_KP_7               327
#define SZ_KEY_KP_8               328
#define SZ_KEY_KP_9               329
#define SZ_KEY_KP_DECIMAL         330
#define SZ_KEY_KP_DIVIDE          331
#define SZ_KEY_KP_MULTIPLY        332
#define SZ_KEY_KP_SUBTRACT        333
#define SZ_KEY_KP_ADD             334
#define SZ_KEY_KP_ENTER           335
#define SZ_KEY_KP_EQUAL           336
#define SZ_KEY_LEFT_SHIFT         340
#define SZ_KEY_LEFT_CONTROL       341
#define SZ_KEY_LEFT_ALT           342
#define SZ_KEY_LEFT_SUPER         343
#define SZ_KEY_RIGHT_SHIFT        344
#define SZ_KEY_RIGHT_CONTROL      345
#define SZ_KEY_RIGHT_ALT          346
#define SZ_KEY_RIGHT_SUPER        347
#define SZ_KEY_MENU               348
#define SZ_KEY_LAST               SZ_KEY_MENU

#define SZ_MOUSE_BUTTON_1         0
#define SZ_MOUSE_BUTTON_2         1
#define SZ_MOUSE_BUTTON_3         2
#define SZ_MOUSE_BUTTON_4         3
#define SZ_MOUSE_BUTTON_5         4
#define SZ_MOUSE_BUTTON_6         5
#define SZ_MOUSE_BUTTON_7         6
#define SZ_MOUSE_BUTTON_8         7
#define SZ_MOUSE_BUTTON_LAST      SZ_MOUSE_BUTTON_8
#define SZ_MOUSE_BUTTON_LEFT      SZ_MOUSE_BUTTON_1
#define SZ_MOUSE_BUTTON_RIGHT     SZ_MOUSE_BUTTON_2
#define SZ_MOUSE_BUTTON_MIDDLE    SZ_MOUSE_BUTTON_3