#include "ModelLoader.h"

bool ModelLoader::isLoad(const std::string& path) {
	std::ifstream input(path);
	if (!input.is_open())
		return false;
	std::string line, startsWith;
	vIndex = 0;
	nIndex = 0;
	tIndex = 0;
	iIndex = 0;
	while (!input.eof()) {
		std::getline(input, line);
		if (line.size() > 1) {
			startsWith = line.substr(0, 2);
			if (startsWith == "v ")
				parceVertices(line);
			else if (startsWith == "vn")
				parceNormal(line);
			else if (startsWith == "vt")
				parceTextureCoords(line);
			else if (startsWith == "f ")
				parceIndices(line);
		}
	}
	return true;
}

void ModelLoader::parceVertices(const std::string& srVertex) {
	int oldIndex = 2;
	int newIndex = srVertex.find(' ', oldIndex+1);
	float x = std::stof(srVertex.substr(oldIndex, newIndex - oldIndex));
	oldIndex = newIndex;
	newIndex = srVertex.find(' ', oldIndex+1);
	float y = std::stof(srVertex.substr(oldIndex, newIndex - oldIndex));
	float z = std::stof(srVertex.substr(newIndex));
	vertices[vIndex * 3] = x;
	vertices[vIndex * 3 + 1] = y;
	vertices[vIndex * 3 + 2] = z;
	vIndex++;
}

void ModelLoader::parceTextureCoords(const std::string& srTextureCoordinate) {
	int oldIndex = 3;
	int newIndex = srTextureCoordinate.find(' ', oldIndex + 1);
	float x = std::stof(srTextureCoordinate.substr(oldIndex, newIndex - oldIndex));
	float y = std::stof(srTextureCoordinate.substr(newIndex));
	texture[tIndex * 2] = x;
	texture[tIndex * 2 + 1] = y;
	tIndex++;
}

void ModelLoader::parceNormal(const std::string& srNormal) {
	int oldIndex = 3;
	int newIndex = srNormal.find(' ', oldIndex + 1);
	float x = std::stof(srNormal.substr(oldIndex, newIndex- oldIndex));
	oldIndex = newIndex;
	newIndex = srNormal.find(' ', oldIndex + 1);
	float y = std::stof(srNormal.substr(oldIndex, newIndex - oldIndex));
	float z = std::stof(srNormal.substr(newIndex));
	normals[nIndex * 3] = x;
	normals[nIndex * 3 + 1] = y;
	normals[nIndex * 3 + 2] = z;
	nIndex++;
}

void ModelLoader::parceIndex(const std::string& srIndex) {
	int oldIndex = srIndex.find('/');
	int v = std::stoi(srIndex.substr(0, oldIndex));
	int newIndex = srIndex.find('/', oldIndex + 1);
	int t = std::stoi(srIndex.substr(oldIndex + 1, newIndex - oldIndex - 1));
	int n = std::stoi(srIndex.substr(newIndex+1));
	v--;
	n--;
	t--;

	fullVertices[iIndex * 8] = vertices[v * 3];
	fullVertices[iIndex * 8 + 1] = vertices[v * 3 + 2];
	fullVertices[iIndex * 8 + 2] = vertices[v * 3 + 1];
	fullVertices[iIndex * 8 + 3] = 0.0;
	fullVertices[iIndex * 8 + 4] = 0.0;
	fullVertices[iIndex * 8 + 5] = 0.0;
	fullVertices[iIndex * 8 + 6] = texture[t * 2];
	fullVertices[iIndex * 8 + 7] = texture[t * 2 + 1];
	indices[iIndex] = iIndex;
	iIndex++;
}

void ModelLoader::parceIndices(const std::string& srIndices) {
	int oldIndex = 2;
	int newIndex = srIndices.find(' ', oldIndex + 1);
	parceIndex(srIndices.substr(oldIndex, newIndex - oldIndex));
	oldIndex = newIndex;
	newIndex = srIndices.find(' ', oldIndex + 1);
	parceIndex(srIndices.substr(oldIndex, newIndex - oldIndex));
	parceIndex(srIndices.substr(newIndex));
}