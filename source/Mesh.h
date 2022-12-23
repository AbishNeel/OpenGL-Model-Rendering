#pragma once
#include "VBO.h"
#include "VAO.h"
#include <vector>
#include "Texture.h"
#include "Shader.h"
#include "Camera.h"

class Mesh
{
public:
	Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures);
	void Draw(Shader& shader, Camera& camera, glm::mat4 matrix, glm::vec3 translation, glm::quat rotation, glm::vec3 scale);

private:
	std::vector<Vertex> _vertices;
	std::vector<GLuint> _indices;
	std::vector<Texture> _textures;
	VAO _vao;
};

