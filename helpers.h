#pragma once

bool FileExists(const char* filename);

bool ArgumentParser(int argc, char* argv[]);

void StartTimer();

int64_t GetDeltaTime();

extern bool debugFinder;

