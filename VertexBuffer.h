#pragma once
#include <glad/glad.h>

class VertexBuffer {
public:
	GLuint m_vbo;
	VertexBuffer();
	VertexBuffer(GLfloat* vertices, GLsizeiptr size);

	void bind();
	void release();
	void destroy();
};