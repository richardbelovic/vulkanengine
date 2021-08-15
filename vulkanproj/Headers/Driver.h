#pragma once

#include "VWindow.h"
#include "VPipeline.h"

namespace vulk
{
class Driver
{
public:
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;

	void run();
private:
	VWindow vWindow{WIDTH, HEIGHT, "My Window" };
	VPipeline vPipeline{ "Shaders/FirstShader.vert.spv", "Shaders/FirstShader.frag.spv" };
	
};
}
