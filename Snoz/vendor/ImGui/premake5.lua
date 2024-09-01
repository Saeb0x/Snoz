project "ImGui"
	kind "StaticLib"
	language "C++"
	staticruntime "On"
	warnings "Off"

	targetdir("../../../bin/" ..outputDir.. "/%{prj.name}")
	objdir("../../../bin-int/" ..outputDir.. "/%{prj.name}")

	files {
		"ImGui/*.cpp",
		"ImGui/*.h"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines {
			"_CRT_SECURE_NO_WARNINGS"
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