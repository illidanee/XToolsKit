#define EXPORT_XAPI
#include "XFileManager.h"

#include <FreeImage.h>

int XFileManager::Init()
{
	FreeImage_Initialise();
	return 0;
}

int XFileManager::Done()
{
	FreeImage_DeInitialise();
	return 0;
}

int XFileManager::LoadImage(unsigned char*& pBuffer, int& w, int& h, const char* pFile)
{
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	fif = FreeImage_GetFileType(pFile);
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(pFile);
	if (fif == FIF_UNKNOWN)
		return -1;

	FIBITMAP* dib = NULL;
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, pFile);
	if (!dib)
		return -2;

	FIBITMAP* temp = dib;
	dib = FreeImage_ConvertTo32Bits(dib);
	FreeImage_Unload(temp);

	BYTE* bit = FreeImage_GetBits(dib);
	w = FreeImage_GetWidth(dib);
	h = FreeImage_GetHeight(dib);

	if ((bit == 0) || (w == 0) || (h == 0))
		return -3;

	size_t size = w * h * 4;
	pBuffer = new unsigned char[size];
	memcpy(pBuffer, bit, size);

	FreeImage_Unload(dib);

	return 0;
}