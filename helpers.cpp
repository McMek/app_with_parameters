#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <map>
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
    map<string, string> argm;

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

    for (const auto& str : args)
    {
        size_t pos = str.find('=');
        if (pos != string::npos)
        {
            string key = str.substr(0, pos);
            string value = str.substr(pos + 1);
            argm[key] = value;
        }
    }

    for (const auto& [key, value] : argm)
    {
        cout << "Key: " << key << "\n" << "Value: " << value << "\n" << endl;
    }
}

