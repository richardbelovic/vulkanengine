#pragma once

#include "../Headers/VEngineDevice.h"
#include <string>
#include <vector>

namespace vulk
{
	struct PipeLineConfigInfo
	{
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};
	class VPipeline
	{
	public:
		VPipeline(
			VEngineDevice &device, 
			const std::string& vertFilepath, 
			const std::string& fragFilepath, 
			const PipeLineConfigInfo& configInfo
		);
		~VPipeline();

		VPipeline(const VPipeline&) = delete;
		void operator=(const VPipeline&) = delete;

		static PipeLineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(
			const std::string& vertFilepath, 
			const std::string& fragFilepath, 
			const PipeLineConfigInfo& configInfo
		);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
		
		VEngineDevice& vEngineDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}
