project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Oberon/vendor/spdlog/include",
		"%{wks.location}/Oberon/src",
		"%{wks.location}/Oberon/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Oberon"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "OB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "OB_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "OB_DIST"
		runtime "Release"
		optimize "on"