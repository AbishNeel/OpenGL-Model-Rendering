#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "VBO.h"
#include "IBO.h"
#include "VAO.h"
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"
#include <glm/glm/glm.hpp>
#include "Mesh.h"
#include "Model.h"
#include <string>
#include <algorithm>

const char* vertexShaderFile = "default.vert";
const char* fragmentShaderFile = "default.frag";
const char* lightVertexShaderFile = "light.vert";
const char* lightFragmentShaderFile = "light.frag";

const unsigned int ScreenWidth = 800;
const unsigned int ScreenHeight = 600;

Vertex lightVertices[] =
{ //     COORDINATES     //
	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

const std::string ModelSelection()
{
	std::string inputString;
	std::cout << "Choose a model to render: Sword/Map/Grindstone/Scroll" << std::endl << ">";
	std::cin >> inputString;
	std::transform(inputString.begin(), inputString.end(), inputString.begin(), tolower);

	while(inputString != "sword" && inputString != "map" && inputString != "grindstone" && inputString != "scroll")
	{
		std::cout << "Invalid model!" << std::endl << ">";
		std::cin >> inputString;
		std::transform(inputString.begin(), inputString.end(), inputString.begin(), tolower);
	}
	return inputString;
}

int main()
{
	std::string modelName = ModelSelection();
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(ScreenWidth, ScreenHeight, "Model Rendering", NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Failed to create window \n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();

	glViewport(0, 0, ScreenWidth, ScreenHeight);

	//Set clear screen value and swap buffers
	glClearColor(.1f, .5f, .3f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	Shader shaderProgram("default.vert", "default.frag");

	Camera camera(glm::vec3(0.f, 30.f, 30.f), ScreenWidth, ScreenHeight);
	camera.UpdateMatrix(45.f, .1f, 5000.f, shaderProgram);

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);


	shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram._ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram._ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	glEnable(GL_DEPTH_TEST);

	std::string modelPath = "../content/models/";
	modelPath += modelName + "/" + modelName + ".gltf";
	Model model(modelPath.c_str());

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.ProcessInput(window);
		camera.UpdateMatrix(45.f, 0.1f, 5000.f, shaderProgram);

		model.Draw(shaderProgram, camera);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}