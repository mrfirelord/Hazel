#include "hzpch.h"
#include "OpenGlContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Hazel {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle) {
		HZ_CORE_ASSERT(windowHandle, "WindowHandle is null!")
	}

	void OpenGLContext::Init() {
		glfwMakeContextCurrent(m_WindowHandle);
		int gladInitStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(gladInitStatus, "Failed to initialize Glad!");

		HZ_CORE_INFO("Vendor {0}", glGetString(GL_VENDOR));
		HZ_CORE_INFO("Renderer {0}", glGetString(GL_RENDERER));
		HZ_CORE_INFO("Version {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(m_WindowHandle);
	}
}