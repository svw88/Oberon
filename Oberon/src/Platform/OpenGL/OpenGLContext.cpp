#include "obpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Oberon {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		OB_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		OB_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		OB_CORE_ASSERT(status, "Failed to initialize Glad!");

		OB_CORE_INFO("OpenGL Info:");
		OB_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		OB_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		OB_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		OB_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Oberon requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		OB_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}