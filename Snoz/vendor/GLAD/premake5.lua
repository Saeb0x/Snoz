project "GLAD"
	kind "StaticLib"
	language "C"
	staticruntime "On"
	warnings "Off"

	targetdir("../../../bin/" ..outputDir.. "/%{prj.name}")
	objdir("../../../bin-int/" ..outputDir.. "/%{prj.name}")

	files {
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs {
		"include"
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
		optimize "On"

	filter "configurations:Dist"
		runtime "Release"
		optimize "On"