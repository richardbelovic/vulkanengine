#include "../Headers/VPipeline.h"


#include <fstream>
#include <iostream>
#include <stdexcept>
namespace vulk
{
	VPipeline::VPipeline(const std::string& vertFilepath, const std::string& fragFilepath)
	{
		createGraphicsPipeline(vertFilepath, fragFilepath);
	}

	void VPipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath)
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



}
