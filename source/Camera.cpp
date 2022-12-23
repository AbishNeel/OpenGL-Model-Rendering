#include "Camera.h"
#include <iostream>

Camera::Camera(glm::vec3 position, int width, int height)
{
	_position = position;
	_width = width;
	_height = height;
}

void Camera::UpdateMatrix(float FOV, float nearPlane, float farPlane, Shader& shader)
{
	glm::mat4 view = glm::mat4(1.f);
	glm::mat4 proj = glm::mat4(1.f);

	view = glm::lookAt(_position, _position + _orientation, _upVector);
	proj = glm::perspective(FOV, (float)_width / _height, nearPlane, farPlane);
	
	cameraMatrix = proj * view;
}

void Camera::UpdateCamMatrixUniform(Shader& shader, const char* uniform)
{
	glUniformMatrix4fv(glGetUniformLocation(shader._ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void Camera::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		_position += _speed * _orientation;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		_position -= _speed * _orientation;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		_position += _speed * glm::normalize(glm::cross(_orientation, _upVector));

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		_position -= _speed * glm::normalize(glm::cross(_orientation, _upVector));

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		_position += _speed * _upVector;

	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		_position -= _speed * _upVector;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (_firstClick)
		{
			glfwSetCursorPos(window, (_width / 2), (_height / 2));
			_firstClick = false;
		}

		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = _sensitivity * (float)(mouseY - (_height / 2)) / _height;
		float rotY = _sensitivity * (float)(mouseX - (_width / 2)) / _width;

		glm::vec3 newOrientation = glm::rotate(_orientation, glm::radians(-rotX), glm::normalize(glm::cross(_orientation, _upVector)));

		if (abs(glm::angle(newOrientation, _upVector) - glm::radians(90.0f)) <= glm::radians(85.0f))
			_orientation = newOrientation;

		_orientation = glm::rotate(_orientation, glm::radians(-rotY), _upVector);

		glfwSetCursorPos(window, (_width / 2), (_height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		_firstClick = true;
	}
}