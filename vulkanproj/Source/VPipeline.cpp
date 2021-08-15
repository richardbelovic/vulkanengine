#include "../Headers/VPipeline.h"


#include <fstream>
#include <iostream>
#include <stdexcept>
namespace vulk
{
	VPipeline::VPipeline(VEngineDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, const PipeLineConfigInfo& configInfo) : vEngineDevice(device)
	{
		createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
	}

	void VPipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipeLineConfigInfo& configInfo)
	{
		auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);

		std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
		std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
	}

	//Reads in compiled shader code and returns the code in a buffer
	std::vector<char> VPipeline::readFile(const std::string& filepath)
	{
		//Opens file in filepath, uses bitflags ios::ate to go to end, and ios::binary to read it in a binary format
		std::ifstream file{ filepath, std::ios::ate | std::ios::binary };

		//Checks if file is open
		if(!file.is_open())
		{
			throw std::runtime_error("failed to open file: " + filepath);
		}

		//Gets file size
		size_t fileSize = static_cast<size_t>(file.tellg());
		//Create a buffer to store the file in memory, as big as it needs to be
		std::vector<char> buffer(fileSize);

		//Goes back to start of file
		file.seekg(0);
		//Reads the file into the buffer
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
		
	}

	void VPipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(vEngineDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create shader modules");
		}
	}

	PipeLineConfigInfo VPipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
	{
		PipeLineConfigInfo configInfo{};

		return configInfo;
	}





}
