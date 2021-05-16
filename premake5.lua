workspace "Oberon"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Oberon"
	location "Oberon"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/tinyobjloader",
		"%{prj.name}/vendor/stb",
		"%{prj.name}/vendor/glfw/include",
		"%{prj.name}/vendor/glm",
		"C:/VulkanSDK/1.2.176.1/Include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"OB_PLATFORM_WINDOWS",
			"OB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "OB_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "OB_Release"
			optimize "On"

		filter "configurations:Dist"
			defines "OB_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Oberon/vendor/spdlog/include",
		"Oberon/src",
	}

	links
	{
		"Oberon"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"OB_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "OB_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "OB_Release"
			optimize "On"

		filter "configurations:Dist"
			defines "OB_DIST"
			optimize "On"