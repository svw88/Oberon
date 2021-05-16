#pragma once

#ifdef OB_PLATFORM_WINDOWS

extern Oberon::Application* Oberon::CreateApplication();

int main(int argc, char** argv)
{
	Oberon::Log::Init();
	OB_CORE_WARN("Initialized Log!");
	int a = 5;
	OB_INFO("Hello! Var={0}", a);

	auto app = Oberon::CreateApplication();
	app->Run();
	delete app;
}

#endif