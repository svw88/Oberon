#include "obpch.h"
#include "Oberon/Renderer/VertexArray.h"

#include "Oberon/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Oberon {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    OB_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		OB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}