#include <iostream>

#include "../XFileManager/XFileManager.h"
#pragma comment(lib, "../bin/Debug/x64/XFileManager.lib")

int main()
{
	XFileManager mgr;
	unsigned char* pBuffer;
	int w;
	int h;
	int ret = mgr.XLoadImage(pBuffer, w, h, "../Resources/1.jpg");

	int a = 100000;
	int b = 100000;
	int c = a * b;
	unsigned long long d = (unsigned long long)a * b;
	return 0;
}