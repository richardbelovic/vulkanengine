#include "../Headers/VWindow.h"

namespace vulk
{
	VWindow::VWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name}
	{
		windowInit();
	}

	VWindow::~VWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	
	void VWindow::windowInit()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

}
