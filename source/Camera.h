#pragma once
#include <glad/glad.h>
#include<glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <GLFW/glfw3.h>
#include <glm/glm/gtx/rotate_vector.hpp>
#include <glm/glm/gtx/vector_angle.hpp>

class Camera
{
public:
	Camera(glm::vec3 position, int width, int height);
	void UpdateMatrix(float FOV, float nearPlane, float farPlane, Shader& shader);
	void UpdateCamMatrixUniform(Shader& shader, const char* uniform);
	void ProcessInput(GLFWwindow* window);
	inline const glm::vec3& Position() const { return _position; }

private:
	int _width, _height;

	float _speed = .01f;
	float _sensitivity = 100.f;

	bool _firstClick = true;

	glm::vec3 _position;
	glm::vec3 _orientation = glm::vec3(0.f, 0.f, -1.f);
	glm::vec3 _upVector = glm::vec3(0.f, 1.f, 0.f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);
};

