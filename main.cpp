#include "helpers.h"

int main(int argc, char* argv[])
{
	ArgumentParser(argc, argv);
	
	if (FileExists("test.txt"))
	{
		cout << "test.txt file detected\n\n";
	}
	else
	{
		cout << "test.txt file not detected\n\n";
	}

	return 0;

}