  
include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Oberon"
	architecture "x86_64"
	startproject "Hazelnut"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Oberon/vendor/GLFW"
	include "Oberon/vendor/Glad"
	include "Oberon/vendor/imgui"
	include "Oberon/vendor/yaml-cpp"
group ""

include "Oberon"
include "Sandbox"