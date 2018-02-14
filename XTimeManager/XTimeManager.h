#ifndef __XTIME_MANAGER_H__
#define __XTIME_MANAGER_H__

#ifdef EXPORT_XAPI
#define XAPI __declspec(dllexport)
#else
#define XAPI __declspec(dllimport)
#endif

#define XIN
#define XOUT

#include <chrono>

class XAPI  XTimeManager
{
public:
	int XInit();
	int XDone();

	void UpdateTime();
	double GetTime();

private:
	std::chrono::time_point<std::chrono::high_resolution_clock>* _LastTimePoint;
};

#endif