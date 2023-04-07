#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
		string match;

		for (int i = 1; i < argc; i++)
		{
			string argi = argv[i];

			if (argi.find("test") == 0)
				match = argi.substr(0, 4);
		}

		bool found = false;

		for (int i = 1; i < argc; i++)
		{
			string argi = argv[i];

			if (argi.find("test") == 0)
				if (argi == match)
					found = true;
		}

		if (found)
		{
			cout << "\n\"Test\" argument initiated" << endl;

			int count;
			cout << "\nCommand-line arguments:\n";
			for (count = 1; count < argc; count++)
				cout << "  argv[" << count << "]   " << argv[count] << "\n";
		}
		else
		{
			cout << "\nUsage: appwithParameters.exe test\n" << endl;
			exit(1);
		}

	cout << "\n";

	return 0;

}