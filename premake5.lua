workspace "MTE"
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
IncludeDir["GLFW"] = "MTE/vendor/GLFW/include"
IncludeDir["Glad"] = "MTE/vendor/Glad/include"
IncludeDir["ImGui"] = "MTE/vendor/imgui"

include "MTE/vendor/GLFW"
include "MTE/vendor/Glad"
include "MTE/vendor/imgui"

project "MTE"
	location "MTE"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "hzpch.h"
	pchsource "MTE/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		runtime "Debug"
		systemversion "latest"

		defines 
		{
				"MTE_PLATFORM_WINDOWS",
				"MTE_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}
		

	filter "configurations:Debug"
		defines "MTE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "MTE_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "MTE_DIST"
		buildoptions "/MD"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"MTE/vendor/spdlog/include;",
		"MTE/src"
	}

	links 
	{
		"MTE"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		runtime "Debug"
		systemversion "latest"

		defines 
		{
				"MTE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MTE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "MTE_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "MTE_DIST"
		buildoptions "/MD"
		symbols "On"