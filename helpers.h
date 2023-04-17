#pragma once

bool FileExists(const char* filename);

bool ArgumentParser(int argc, char* argv[]);

void StartTimer();

double GetDeltaTime();

extern bool debugFinder;

