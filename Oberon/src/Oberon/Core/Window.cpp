#include "obpch.h"
#include "Oberon/Core/Window.h"

#ifdef OB_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Oberon
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef OB_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		OB_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}