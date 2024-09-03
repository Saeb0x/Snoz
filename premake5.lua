workspace "Snoz"
	architecture "x64"

	-- Supported only by Visual Studio ------
	startproject "Sandbox"
	-----------------------------------------

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Snoz"

group "Dependencies"
	include "Snoz/vendor/GLFW"
	include "Snoz/vendor/GLAD"
	include "Snoz/vendor/ImGui"
group ""

group "Examples"
	include "Sandbox"
group ""