#ifndef KEYBORAD_H
#define KEYBORAD_H

#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <unistd.h>
#endif

void DetectarTecla();

#endif
