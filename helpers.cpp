#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <filesystem>
#include <vector>
#include <algorithm>
#include "helpers.h"
using namespace std;

bool FileExists(const char* filename)
{
	if (filesystem::exists(filename))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ArgumentParser(int argc, char* argv[])
{
	vector<string> args;

	int i;

	for (i = 1; i < argc; i++) {
		args.push_back(argv[i]);
	}

	sort(args.begin(), args.end());

	if (find(args.begin(), args.end(), "test") != args.end())
	{
		cout << "\n\"Test\" argument initiated\n" << "\nCommand-line arguments:\n";

		for (i = 0; i < args.size(); i++)
			cout << "argv[" << i + 1 << "] " << args[i] << "\n";
	}
	else
	{
		cout << "\nUsage: appwithParameters.exe test\n" << endl;
		exit(1);
	}

	cout << endl;

	//adding string check for "=" sign

	for (int i = 1; i < argc; i++)
	{
		string argi = argv[i];

		if (argi.find('=') != string::npos)
		{
			ofstream writearg;
			writearg.open("test1.txt");
			writearg << argv[i];
			writearg.close();

			ifstream in("test1.txt");
			stringstream buffer;
			buffer << in.rdbuf();
			string test = buffer.str();
			cout << "Equal sign found at " << test << " argument." << endl << endl;

			size_t pos1 = 0;
			size_t pos2;

			string str;
			string str2;
			pos2 = test.find("=", pos1);

			str = test.substr(pos1, (pos2 - pos1));
			cout << "Argument: \"" << str << "\" initiated with its: ";

			pos2 = pos2 + 1;
			str2 = test.substr(pos2, (pos1 - pos2));
			cout << "\"" << str2 << "\" optional argument\n" << endl;
			in.close();

		}

		const int result = remove("test1.txt");

	}
}

