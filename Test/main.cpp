#include <iostream>

#include "../XFileManager/XFileManager.h"
#pragma comment(lib, "../bin/Release/x64/XFileManager.lib")

#include "../XTimeManager/XTimeManager.h"
#pragma comment(lib, "../bin/Release/x64/XTimeManager.lib")

int main()
{
	/************************************************************************/
	/*                  XTimeManager                                        */
	/************************************************************************/
	XTimeManager timeMgr;
	timeMgr.XInit();
	timeMgr.UpdateTime();


	/************************************************************************/
	/*                  XFileManager                                        */
	/************************************************************************/
	XFileManager fileMgr;
	unsigned char* pBuffer;
	int w;
	int h;
	int ret = fileMgr.XLoadImage(pBuffer, w, h, "../Resources/1.jpg");

	int a = 100000;
	int b = 100000;
	int c = a * b;
	unsigned long long d = (unsigned long long)a * b;


	/************************************************************************/
	/*                  XTimeManager                                        */
	/************************************************************************/
	std::cout << timeMgr.GetTime() << std::endl;
	timeMgr.XDone();

	return 0;
}