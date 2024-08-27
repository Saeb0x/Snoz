project "Snoz"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"

	targetdir("../bin/" ..outputDir.. "/%{prj.name}")
	objdir("../bin-int/" ..outputDir.. "/%{prj.name}")

	files {
		"src/**.h",
		"src/**.cpp"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		systemversion "latest"

		defines {

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