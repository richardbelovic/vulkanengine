#include "../Headers/Driver.h"

#include <stdexcept>

namespace vulk
{
	Driver::Driver()
	{
		createPipelineLayout();
		createPipeline();
		createCommandBuffers();
	}

	Driver::~Driver()
	{
		vkDestroyPipelineLayout(vEngineDevice.device(), pipelineLayout, nullptr);
	}


	void Driver::run()
	{
		while(!vWindow.shouldClose())
		{
			glfwPollEvents(); //polls for events like keystrokes or clicking buttons
		}
	}
	void Driver::createPipelineLayout()
	{
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;
		if(vkCreatePipelineLayout(vEngineDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create pipeline layout");
		}
	}
	void Driver::createPipeline()
	{
		auto pipeLineConfig = VPipeline::defaultPipelineConfigInfo(vSwapChain.width(), vSwapChain.height());
		pipeLineConfig.renderPass = vSwapChain.getRenderPass();
		pipeLineConfig.pipelineLayout = pipelineLayout;
		vPipeline = std::make_unique<VPipeline>(
		vEngineDevice,
		"Shaders/FirstShader.vert.spv",
		"Shaders/FirstShader.frag.spv",
		pipeLineConfig);
	}
	void Driver::createCommandBuffers()
	{
		
	}
	void Driver::drawFrame()
	{
		
	}
}
