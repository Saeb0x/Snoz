#pragma once

#include "Snoz/Renderer/Buffer.h"
#include "VertexBufferLayout.h"

namespace Snoz
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

		void Bind();
		void Unbind();

	private:
		unsigned int m_VertexArrayID;
	};
}

