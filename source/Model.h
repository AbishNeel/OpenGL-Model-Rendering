#pragma once
#include <njson/json.h>
#include"Mesh.h"

class Model
{
public:
	Model(const char* file);

	void Draw(Shader& shader, Camera& camera);

private:
	const char* file;
	std::vector<unsigned char> _data;
	nlohmann::json _JSON;

	std::vector<Mesh> meshes;
	std::vector<glm::vec3> _translationsMeshes;
	std::vector<glm::quat> _rotationsMeshes;
	std::vector<glm::vec3> _scalesMeshes;
	std::vector<glm::mat4> _matricesMeshes;

	std::vector<std::string> _loadedTexName;
	std::vector<Texture> _loadedTex;

	void LoadMesh(unsigned int indMesh);

	void TraverseNode(unsigned int nextNode, glm::mat4 matrix = glm::mat4(1.0f));

	std::vector<unsigned char> GetData();
	std::vector<float> GetFloats(nlohmann::json accessor);
	std::vector<GLuint> GetIndices(nlohmann::json accessor);
	std::vector<Texture> GetTextures();

	std::vector<Vertex> AssembleVertices(std::vector<glm::vec3> positions, std::vector<glm::vec3> normals, std::vector<glm::vec2> texUVs);

	std::vector<glm::vec2> GroupFloatsVec2(std::vector<float> floatVec);
	std::vector<glm::vec3> GroupFloatsVec3(std::vector<float> floatVec);
	std::vector<glm::vec4> GroupFloatsVec4(std::vector<float> floatVec);
};