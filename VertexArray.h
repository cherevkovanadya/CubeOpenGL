#pragma once
#include <glad/glad.h>
#include "VertexBuffer.h"

class VertexArray
{
public:
	GLuint m_vao;

	VertexArray();
	void create();
	void link(VertexBuffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void bind();
	void release();
	void destroy();
};