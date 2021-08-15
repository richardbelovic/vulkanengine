#include "../Headers/Driver.h"

namespace vulk
{
	void Driver::run()
	{
		while(!vWindow.shouldClose())
		{
			glfwPollEvents(); //polls for events like keystrokes or clicking buttons
		}
	}
}
