#pragma once

#include <vector>

#include "Snoz/Log.h"

#define GL_FLOAT 0x1406
#define GL_INT 0x1404
#define GL_UNSIGNED_BYTE 0x1401
#define GL_FALSE 0

namespace Snoz
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;

		static unsigned int GetSizeOfType(unsigned int type)
		{
			switch (type)
			{
				case GL_FLOAT:
				case GL_INT: return 4;
				case GL_UNSIGNED_BYTE: return 1;
			};

			SZ_ASSERT(false, "Invalid OpenGL type!");
			return 0;
		}
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout() : m_Stride(0) {};

		template<typename T>
		void Push(unsigned int count) 
		{
			static_assert(false);
		}

		template<>
		void Push<float>(unsigned int count)
		{
			m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
			m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
		}

		template<>
		void Push<int>(unsigned int count)
		{
			m_Elements.push_back({ GL_INT, count, GL_FALSE });
			m_Stride += count * VertexBufferElement::GetSizeOfType(GL_INT);
		}

		const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
		const unsigned int GetStride() const { return m_Stride; }
	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride;
	};
}