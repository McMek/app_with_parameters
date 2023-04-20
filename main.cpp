#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <filesystem>
#include "helpers.h"

int main(int argc, char* argv[])
{
	StartTimer();
	
	if (!ArgumentParser(argc, argv))
		return 1;
	
	if (FileExists("test.txt"))
	{
		std::cout << "test.txt file detected\n\n";
	}
	else
	{
		std::cout << "test.txt file not detected\n\n";
	}

	if (debugFinder)
	{
		std::cout << "Elapsed time: " << GetDeltaTime() << " milliseconds\n" << std::endl;
	}

	return 0;

}