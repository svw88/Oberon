#include "obpch.h"
#include "Oberon/Renderer/RenderCommand.h"

namespace Oberon {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}