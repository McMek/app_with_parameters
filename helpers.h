#pragma once

bool FileExists(const char* filename);

bool ArgumentParser(int argc, char* argv[]);

void StartTimer();

double GetDeltaTime();

extern bool debugFinder;

//bool DebugFinder(int argc, char* argv[]);

