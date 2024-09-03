project "Snoz"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir("../bin/" ..outputDir.. "/%{prj.name}")
	objdir("../bin-int/" ..outputDir.. "/%{prj.name}")

	includeDirs = {}
	includeDirs["spdlog"] = "vendor/spdlog/include"
	includeDirs["GLFW"] = "vendor/GLFW/GLFW/include"
	includeDirs["GLAD"] = "vendor/GLAD/include"
	includeDirs["ImGui"] = "vendor/ImGui/ImGui"

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src",
		"%{includeDirs.spdlog}",
		"%{includeDirs.GLFW}",
		"%{includeDirs.GLAD}",
		"%{includeDirs.ImGui}"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	links {
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	pchheader "szPCH.h"
	pchsource "src/Snoz/szPCH.cpp"

	filter "system:windows"
		systemversion "latest"

		defines {
			"SZ_PLATFORM_WINDOWS",
			"SZ_BUILD_DLL"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		runtime "Release"
		optimize "On"