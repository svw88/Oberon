#pragma once
#include "Oberon/Core/Base.h"
#include "Oberon/Core/Application.h"

#ifdef OB_PLATFORM_WINDOWS

extern Oberon::Application* Oberon::CreateApplication();

int main(int argc, char** argv)
{
	Oberon::Log::Init();

	OB_PROFILE_BEGIN_SESSION("Startup", "OberonProfile-Startup.json");
	auto app = Oberon::CreateApplication();
	OB_PROFILE_END_SESSION();

	OB_PROFILE_BEGIN_SESSION("Runtime", "OberonProfile-Runtime.json");
	app->Run();
	OB_PROFILE_END_SESSION();

	OB_PROFILE_BEGIN_SESSION("Shutdown", "OberonProfile-Shutdown.json");
	delete app;
	OB_PROFILE_END_SESSION();
}

#endif