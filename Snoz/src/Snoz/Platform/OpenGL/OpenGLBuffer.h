#pragma once
#include "Snoz/Renderer/Buffer.h"

namespace Snoz
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, unsigned int size);
		~OpenGLVertexBuffer() override;

		void Bind() const override;
		void Unbind() const override;
	private:
		unsigned int m_VertexBufferID;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int* indices, unsigned int count);
		~OpenGLIndexBuffer() override;

		void Bind() const override;
		void Unbind() const override;

		inline unsigned int GetCount() const override { return m_Count; }
	private:
		unsigned int m_IndexBufferID;
		unsigned int m_Count;
	};
}
