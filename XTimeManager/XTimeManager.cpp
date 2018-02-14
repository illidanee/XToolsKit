#define EXPORT_XAPI
#include "XTimeManager.h"

int XTimeManager::XInit()
{
	_LastTimePoint = new std::chrono::time_point<std::chrono::high_resolution_clock>();
	return 0;
}

int XTimeManager::XDone()
{
	delete _LastTimePoint;
	return 0;
}

void XTimeManager::UpdateTime()
{
	*_LastTimePoint = std::chrono::high_resolution_clock::now();
}

double XTimeManager::GetTime()
{
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds t = std::chrono::duration_cast<std::chrono::microseconds>(end - *_LastTimePoint);
	return t.count() * 0.000001;
}