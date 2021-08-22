#include "hzpch.h"
#include "Buffer.h"
#include "Hazel/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Hazel {
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::OpenGL:	return CreateRef<OpenGLVertexBuffer>(vertices, size);
		case RendererAPI::API::None:	HZ_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;
		}

		HZ_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	uint32_t IndexBuffer::GetCount() const {
		return uint32_t();
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indeces, uint32_t size) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::OpenGL:	return CreateRef<OpenGLIndexBuffer>(indeces, size);
		case RendererAPI::API::None:	HZ_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;
		}

		HZ_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
