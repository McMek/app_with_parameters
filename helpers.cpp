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

bool FileExists(const char* filename)
{
    if (std::filesystem::exists(filename))
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
    std::vector<std::string> args(argv + 1, argv + argc);
    std::map<std::string, std::string> argm;

    if (find(args.begin(), args.end(), "test") != args.end())
    {   
        if (find(args.begin(), args.end(), "debug") != args.end())
        {
            debugFinder = true;
        }
        
        for (const auto& str : args)
        {
            size_t pos = str.find('=');
            if (pos != std::string::npos)
            {
                std::string key = str.substr(0, pos);
                std::string value = str.substr(pos + 1);
                argm[key] = value;
            }
        }

        std::cout << std::endl;

        for (const auto& [key, value] : argm)
        {
            std::cout << "Key: " << key << "\n" << "Value: " << value << "\n" << std::endl;
        }

        return true;
    }
    else
    {
        std::cout << "\nUsage: appwithParameters.exe test\n" << std::endl;
       
        return false;
    }
}

int64_t timerStartedAt;

void StartTimer()
{
    timerStartedAt = duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int64_t GetDeltaTime()
{
    int64_t currentTime = duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    return currentTime - timerStartedAt;
}



