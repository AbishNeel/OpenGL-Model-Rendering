#include "Shader.h"
#include <string>
#include "Utilities.h"
#include <iostream>

using namespace std;

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	string vertexCode = Utilities::GetFileContents(vertexShaderSource);
	string fragmentCode = Utilities::GetFileContents(fragmentShaderSource);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	CompileErrors(vertexShader, "VERTEX");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	CompileErrors(fragmentShader, "FRAGMENT");


	//Creating and linking shader program
	_ID = glCreateProgram();
	glAttachShader(_ID, vertexShader);
	glAttachShader(_ID, fragmentShader);
	glLinkProgram(_ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(_ID);
}

void Shader::Delete()
{
	glDeleteProgram(_ID);
}

void Shader::CompileErrors(unsigned int shader, const char* type)
{
	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			cout << "Shader compilation error for " << type << endl;
		}
	}
	else
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			cout << "Shader linking error for " << type << endl;
		}
	}

}