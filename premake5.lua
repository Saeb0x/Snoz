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

group "Dependencies"
	include "Snoz/vendor/GLFW"
	include "Snoz/vendor/GLAD"
group ""

include "Snoz"

group "Examples"
	include "Sandbox"
group ""