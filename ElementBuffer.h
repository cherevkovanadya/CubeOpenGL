#pragma once
#include<glad/glad.h>

class ElementBuffer
{
public:

	GLuint m_ebo;
	ElementBuffer();
	ElementBuffer(GLuint* indices, GLsizeiptr size);
	void bind();
	void release();
	void destroy();
};