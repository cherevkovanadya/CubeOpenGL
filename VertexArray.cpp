#include "VertexArray.h"

VertexArray::VertexArray() {}

void VertexArray::create() {
	glGenVertexArrays(1, &m_vao);
}

void VertexArray::link(VertexBuffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
	VBO.bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.release();
}

void VertexArray::bind() {
	glBindVertexArray(m_vao);
}

void VertexArray::release() {
	glBindVertexArray(0);
}

void VertexArray::destroy() {
	glDeleteVertexArrays(1, &m_vao);
}