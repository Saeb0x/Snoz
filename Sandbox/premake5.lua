project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"

	targetdir("../bin/" ..outputDir.. "/%{prj.name}")
	objdir("../bin-int/" ..outputDir.. "/%{prj.name}")

	files {
		"src/**.h",
		"src/**.cpp"
	}

	links {
		"Snoz"
	}

	includedirs {
		"../Snoz/src"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"SZ_PLATFORM_WINDOWS"
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