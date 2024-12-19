workspace "Chinatsu"

	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Chinatsu/vendor/GLFW/include"

include "Chinatsu/vendor/GLFW"

project "Chinatsu"
	location "Chinatsu"
	kind "SharedLib"
	language "C++"
	-- dir for output
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cnpch.h"
	pchsource "Chinatsu/src/cnpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}


	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }
		
		defines
		{
			"CN_PLATFORM_WINDOWS",
			"CN_BUILD_DLL"
		}


		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CN_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "CN_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "CN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	-- dir for output
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Chinatsu/vendor/spdlog/include",
		"Chinatsu/src"
	}

	links
	{
		"Chinatsu"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }
		
		defines
		{
			"CN_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "CN_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "CN_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "CN_DIST"
		optimize "On"