#pragma once

#ifdef OB_PLATFORM_WINDOWS

extern Oberon::Application* Oberon::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Oberon::CreateApplication();
	app->Run();
	delete app;
}

#endif