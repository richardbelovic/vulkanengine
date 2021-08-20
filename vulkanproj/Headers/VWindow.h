#pragma once

#define GLFW_INCLUDE_VULKAN
#include <string>
#include "GLFW/glfw3.h"

namespace vulk
{
class VWindow
{
private:
	void windowInit();

	const int width;
	const int height;

	std::string windowName;
	GLFWwindow* window;
public:
	VWindow(int w, int h, std::string name); //Constructor
	~VWindow(); //Destructor

	//Doesn't allow copying of window 
	VWindow(const VWindow&) = delete; 
	VWindow& operator=(const VWindow&) = delete;
	
	bool shouldClose() { return glfwWindowShouldClose(window); }
	VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }
	
	void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
};
}
