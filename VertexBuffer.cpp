#include "VertexBuffer.h"


VertexBuffer::VertexBuffer() {}

VertexBuffer::VertexBuffer(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VertexBuffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
}

void VertexBuffer::release() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::destroy() {
	glDeleteBuffers(1, &m_vbo);
}