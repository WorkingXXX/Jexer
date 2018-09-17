
#include <iostream>

#include "JexerWindow.h"

using namespace std;

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glfw3.lib")

int main()
{

	if (glfwInit())
	{
		Jexer::JexerWindow win(100, 100, "Test Window");

		glfwMakeContextCurrent(win.GetHandle());

		while (!glfwWindowShouldClose(win.GetHandle()))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(win.GetHandle());
			glfwPollEvents();
		}

		glfwTerminate();

	}

	system("pause");
}