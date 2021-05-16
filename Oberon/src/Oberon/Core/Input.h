#pragma once

#include <glm/glm.hpp>

#include "Oberon/Core/KeyCodes.h"
#include "Oberon/Core/MouseCodes.h"

namespace Oberon {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}