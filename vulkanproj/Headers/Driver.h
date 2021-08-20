#pragma once

#include "VWindow.h"
#include "VPipeline.h"
#include "VEngineDevice.h"
#include "VSwapChain.h"

#include <memory>
#include <vector>
namespace vulk
{
class Driver
{
public:
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;

	Driver();
	~Driver();

	Driver(const Driver &) = delete;
	Driver& operator=(const Driver&) = delete;
	
	void run();
private:
	void createPipelineLayout();
	void createPipeline();
	void createCommandBuffers();
	void drawFrame();
	
	VWindow vWindow{WIDTH, HEIGHT, "My Window" };
	VEngineDevice vEngineDevice{ vWindow };
	VSwapChain vSwapChain{ vEngineDevice, vWindow.getExtent() };
	std::unique_ptr<VPipeline> vPipeline;
	VkPipelineLayout pipelineLayout;
	std::vector<VkCommandBuffer> commandBuffers;

	
};
}
