
#include <iostream>

#include "JexerWindow.h"
#include "JexerShaderProgramCreator.h"

using namespace std;

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment

enum VAO_IDs
{
	Triangles,
	NumVAOs
};

enum Buffer_IDs
{
	ArrayBuffer,
	NumBuffers
};

enum Attrib_IDs
{
	vPosition = 0
};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

void Init()
{
	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	GLfloat vertices[NumVertices][2] =
	{
		{ -0.9, -0.9 },
		{ 0.85, -0.9 },
		{ -0.9, 0.85 },
		{ 0.9, -0.85 },
		{ 0.9,  0.9  },
		{ -0.85, 0.9 }
	};

	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	Jexer::JexerShader vertexShader(Jexer::JexerShaderType::JEXER_VERTEX_SHADER, "TestVertexShader.glsl");
	Jexer::JexerShader pixelShader(Jexer::JexerShaderType::JEXER_PIXEL_SHADER, "TestPixelShader.glsl");

	Jexer::JexerShaderSlot shaderSlot;
	shaderSlot.InsertShader(vertexShader);
	shaderSlot.InsertShader(pixelShader);

	Jexer::JexerShaderProgramCreator shaderPrgmCtr(shaderSlot);
	GLuint prgmId = shaderPrgmCtr.CreateShaderProgram();
	shaderPrgmCtr.UseCurrentShaderProgram();

	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, static_cast<const void*>(0));
	glEnableVertexAttribArray(vPosition);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	glFlush();
}

int main()
{
	if (glfwInit())
	{
		Jexer::JexerWindow win(400, 400, "Test_Shader");

		glfwMakeContextCurrent(win.GetHandle());

		glewInit();
	
		

		while (!glfwWindowShouldClose(win.GetHandle()))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			Display();

			glfwSwapBuffers(win.GetHandle());
			glfwPollEvents();
		}

		glfwTerminate();

	}

	glfwTerminate();
	system("pause");
}