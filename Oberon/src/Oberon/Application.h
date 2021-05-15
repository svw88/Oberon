#pragma once

#include "Core.h"

namespace Oberon {

	class OBERON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}



