#pragma once
#include <string>
#include <fstream>
#include <glm/glm.hpp>
#include<glad/glad.h>

class ModelLoader {
public:
	ModelLoader() {}
	bool isLoad(const std::string& path);
	float getV(int index) {
		return fullVertices[index];
	}
	GLuint getI(int i) {
		return indices[i];
	}
private:
	void parceVertices(const std::string& srVertex);
	void parceTextureCoords(const std::string& srTextureCoordinate);
	void parceNormal(const std::string& srNormal);
	void parceIndex(const std::string& srIndex);
	void parceIndices(const std::string& srIndices);

	float vertices[3 * 8];
	int vIndex;
	float normals[3 * 6];
	int nIndex;
	float texture[2 * 14];
	int tIndex;
	float fullVertices[12 * 3 * 8];
	GLuint indices[12 * 3];
	int iIndex;
};