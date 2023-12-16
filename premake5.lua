workspace "MTE"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MTE"
	location "MTE"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
				"MTE_PLATFORM_WINDOWS",
				"MTE_BUILD_DLL"
		}

		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}
		

	filter "configurations:Debug"
		defines "MTE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MTE_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "MTE_DIST"
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
		staticruntime "On"
		systemversion "latest"

		defines 
		{
				"MTE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MTE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MTE_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "MTE_DIST"
		symbols "On"