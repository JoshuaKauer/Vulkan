#include "RenderEngine.h"
#include <iostream>

int main() 
{
	RenderEngine app;

	try 
	{
		app.Run();
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}