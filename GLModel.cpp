#include "GLModel.h"

GLModel::GLModel(ModelLoader loader) {
	for (int i = 0; i < 3 * 12 * 8; i++)
		vertices[i] = loader.getV(i);
	for (int i = 0; i < 3 * 12; i++)
		indices[i] = loader.getI(i);
}

void GLModel::link() {
	shader = Shader("default.vert", "default.frag");
	VAO1 = VertexArray();
	VAO1.create();
	VAO1.bind();
	VBO1 = VertexBuffer(vertices, sizeof(vertices));
	EBO1 = ElementBuffer(indices, sizeof(indices));

	VAO1.link(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.link(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.link(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
}

void GLModel::bind() {
	tex.bind();
	VAO1.bind();
}

void GLModel::release() {
	VAO1.release();
	VBO1.release();
	EBO1.release();
}

void GLModel::destroy() {
	VAO1.destroy();
	VBO1.destroy();
	EBO1.destroy();
	tex.destroy();
	shader.destroy();
}

int GLModel::nVertices() {
	return 3 * 12;
}

GLuint GLModel::getShaderId() {
	return shader.m_shaderId;
}

void GLModel::activateShader() {
	shader.activate();
}

void GLModel::setTexture() {
	tex = Texture("gradient.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	tex.texUnit(shader, "tex0", 0);
}