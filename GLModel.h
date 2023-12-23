#pragma once
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include "Texture.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "ModelLoader.h"
#include "GLModel.h"
#include "DrawableObject.h"
#include "ModelLoader.h"

class GLModel : public DrawableObject {
public:
	GLModel(ModelLoader loader);
	void link();
	void bind() override;
	void release() override;
	void destroy() override;
	int nVertices() override;
	GLuint getShaderId();
	void activateShader();
	void setTexture();
private:
	VertexArray VAO1;
	VertexBuffer VBO1;
	ElementBuffer EBO1;
	Shader shader;
	Texture tex;

	float vertices[3 * 12 * 8];
	GLuint indices[3 * 12];
};