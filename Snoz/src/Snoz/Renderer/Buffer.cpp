#include "szPCH.h"
#include "Buffer.h"
#include "Renderer.h"
#include "Snoz/Core.h"
#include "Snoz/Platform/OpenGL/OpenGLBuffer.h"
#include "Snoz/Log.h"

namespace Snoz
{
	VertexBuffer* VertexBuffer::Create(float* vertices, unsigned int size)
	{
		switch(Renderer::GetCurrentAPI())
		{
		case RendererAPI::None:
			SZ_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		}

		SZ_ASSERT(false, "Renderer API is not supported!")
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(unsigned int* indices, unsigned int count)
	{
		switch (Renderer::GetCurrentAPI())
		{
		case RendererAPI::None:
			SZ_ASSERT(false, "RendererAPI::None is not supported");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, count);
		}

		SZ_ASSERT(false, "Renderer API is not supported!")
			return nullptr;
	}
}
