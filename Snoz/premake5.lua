project "Snoz"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"

	targetdir("../bin/" ..outputDir.. "/%{prj.name}")
	objdir("../bin-int/" ..outputDir.. "/%{prj.name}")

	includeDirs = {}
	includeDirs["spdlog"] = "vendor/spdlog/include"
	includeDirs["GLFW"] = "vendor/GLFW/GLFW/include"

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src",
		"%{includeDirs.spdlog}",
		"%{includeDirs.GLFW}"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	links {
		"GLFW",
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

		postbuildcommands {
		-- This copies the built Snoz.dll to the appropriate Sandbox directory
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputDir .. "/Sandbox/\"")
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "Speed"

	filter "configurations:Dist"
		runtime "Release"
		optimize "Speed"
		symbols "Off"