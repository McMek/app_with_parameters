#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <filesystem>
using namespace std;

bool FileExists(const char* filename);

void ArgumentParser(int argc, char* argv[]);
