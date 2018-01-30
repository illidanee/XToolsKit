#ifndef __XFILE_MANAGER_H__
#define __XFILE_MANAGER_H__

#ifdef EXPORT_XAPI
#define XAPI __declspec(dllexport)
#else
#define XAPI __declspec(dllimport)
#endif

class XAPI  XFileManager
{
public:
	int Init();
	int Done();

	int LoadImage(unsigned char*& pBuffer, int& w, int& h, const char* pFile);
};

#endif