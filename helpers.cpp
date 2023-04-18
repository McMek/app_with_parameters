#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
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

bool debugFinder = false;

bool ArgumentParser(int argc, char* argv[])
{
    vector<string> args(argv + 1, argv + argc);
    map<string, string> argm;

    if (find(args.begin(), args.end(), "test") != args.end())
    {   
        if (find(args.begin(), args.end(), "debug") != args.end())
        {
            debugFinder = true;
        }
        
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

        cout << endl;

        for (const auto& [key, value] : argm)
        {
            cout << "Key: " << key << "\n" << "Value: " << value << "\n" << endl;
        }

        return true;
    }
    else
    {
        cout << "\nUsage: appwithParameters.exe test\n" << endl;
       
        return false;
    }
}

int64_t timerStartedAt;

void StartTimer()
{
    using namespace std::chrono;
    timerStartedAt = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

double GetDeltaTime()
{
    using namespace std::chrono;
    int64_t currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    return static_cast<double>(currentTime - timerStartedAt);
}



