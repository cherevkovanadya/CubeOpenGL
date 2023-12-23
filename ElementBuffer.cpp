#include"ElementBuffer.h"


ElementBuffer::ElementBuffer() {}

ElementBuffer::ElementBuffer(GLuint* indices, GLsizeiptr size) {
	glGenBuffers(1, &m_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void ElementBuffer::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
}

void ElementBuffer::release() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBuffer::destroy() {
	glDeleteBuffers(1, &m_ebo);
}