#include <iostream>

#include "../XFileManager/XFileManager.h"
#pragma comment(lib, "../bin/Debug/x64/XFileManager.lib")

int main()
{
	XFileManager mgr;
	unsigned char* pBuffer;
	int w;
	int h;
	int ret = mgr.LoadImage(pBuffer, w, h, "../Resources/1.jpg");

	return 0;
}