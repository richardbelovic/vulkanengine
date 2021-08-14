#include "Driver.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
int main()
{
	vulk::Driver driver{};

	try
	{
		driver.run();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}