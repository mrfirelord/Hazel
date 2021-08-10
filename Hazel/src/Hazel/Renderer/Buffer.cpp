#include "hzpch.h"
#include "Buffer.h"

#include "Renderer.h";
#include "Platform/OpenGL/OpenGLBuffer.h";

namespace Hazel {
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::OpenGL:	return new OpenGLVertexBuffer(vertices, size);
		case RendererAPI::API::None:	HZ_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;
		}

		HZ_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	uint32_t IndexBuffer::GetCount() const {
		return uint32_t();
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indeces, uint32_t size) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::OpenGL:	return new OpenGLIndexBuffer(indeces, size);
		case RendererAPI::API::None:	HZ_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;
		}

		HZ_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}