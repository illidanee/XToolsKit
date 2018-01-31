#define EXPORT_XAPI
#include "XFileManager.h"

#include <FreeImage.h>

int XFileManager::XInit()
{
#ifdef FREEIMAGE_LIB
	FreeImage_Initialise();
#endif
	return 0;
}

int XFileManager::XDone()
{
#ifdef FREEIMAGE_LIB
	FreeImage_DeInitialise();
#endif
	return 0;
}

int XFileManager::XLoadImage(XOUT unsigned char*& pBuffer, XOUT int& w, XOUT int& h, XIN const char* pFile)
{
	//�ж��ļ�����
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	fif = FreeImage_GetFileType(pFile);
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(pFile);
	if (fif == FIF_UNKNOWN)
		return -1;

	//�����ļ�
	FIBITMAP* dib = NULL;
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, pFile);
	if (!dib)
		return -2;

	//ת���ļ���ʽ
	FIBITMAP* temp = dib;
	dib = FreeImage_ConvertTo32Bits(dib);
	FreeImage_Unload(temp);

	//��ȡ�ļ���Ϣ
	BYTE* bit = FreeImage_GetBits(dib);
	w = FreeImage_GetWidth(dib);
	h = FreeImage_GetHeight(dib);

	if ((bit == 0) || (w == 0) || (h == 0))
		return -3;

	//�����ļ�
	size_t size = w * h * 4;
	pBuffer = new unsigned char[size];
	memcpy(pBuffer, bit, size);

	//�ͷ���Դ
	FreeImage_Unload(dib);

	return 0;
}

int XFileManager::XSaveImage(XOUT unsigned char*& pBuffer, XOUT int& w, XOUT int& h, XIN const char* pFile)
{
	//����һ�����32λ��ͼƬ
	FIBITMAP* dib = FreeImage_Allocate(w, h, 32);

	//��ȡ�ļ�ָ��
	unsigned char* pPixel = FreeImage_GetBits(dib);

	//��������
	size_t size = w * h;
	for (unsigned int i = 0; i < size; ++i)
	{
		pPixel[i * 4 + 0] = pBuffer[i * 4 + 0];
		pPixel[i * 4 + 1] = pBuffer[i * 4 + 1];
		pPixel[i * 4 + 2] = pBuffer[i * 4 + 2];
		pPixel[i * 4 + 3] = pBuffer[i * 4 + 3];
	}

	//�����ļ�
	FreeImage_Save(FIF_PNG, dib, pFile, PNG_DEFAULT);

	//�ͷ���Դ
	FreeImage_Unload(dib);

	return 0;
}

int XFileManager::XSaveImageRed(XOUT unsigned char*& pBuffer, XOUT int& w, XOUT int& h, XIN const char* pFile)
{
	FIBITMAP* dib = FreeImage_Allocate(w, h, 32);
	unsigned char* pPixel = FreeImage_GetBits(dib);
	size_t size = w * h;
	for (unsigned int i = 0; i < size; ++i)
	{
		pPixel[i * 4 + 0] = pBuffer[i];
		pPixel[i * 4 + 1] = 0;
		pPixel[i * 4 + 2] = 0;
		pPixel[i * 4 + 3] = 255;
	}
	FreeImage_Save(FIF_PNG, dib, pFile, PNG_DEFAULT);
	FreeImage_Unload(dib);

	return 0;
}

int XFileManager::XSaveImageGreen(XOUT unsigned char*& pBuffer, XOUT int& w, XOUT int& h, XIN const char* pFile)
{
	FIBITMAP* dib = FreeImage_Allocate(w, h, 32);
	unsigned char* pPixel = FreeImage_GetBits(dib);
	size_t size = w * h;
	for (unsigned int i = 0; i < size; ++i)
	{
		pPixel[i * 4 + 0] = 0;
		pPixel[i * 4 + 1] = pBuffer[i];
		pPixel[i * 4 + 2] = 0;
		pPixel[i * 4 + 3] = 255;
	}
	FreeImage_Save(FIF_PNG, dib, pFile, PNG_DEFAULT);
	FreeImage_Unload(dib);

	return 0;
}

int XFileManager::XSaveImageBlue(XOUT unsigned char*& pBuffer, XOUT int& w, XOUT int& h, XIN const char* pFile)
{
	FIBITMAP* dib = FreeImage_Allocate(w, h, 32);
	unsigned char* pPixel = FreeImage_GetBits(dib);
	size_t size = w * h;
	for (unsigned int i = 0; i < size; ++i)
	{
		pPixel[i * 4 + 0] = 0;
		pPixel[i * 4 + 1] = 0;
		pPixel[i * 4 + 2] = pBuffer[i];
		pPixel[i * 4 + 3] = 255;
	}
	FreeImage_Save(FIF_PNG, dib, pFile, PNG_DEFAULT);
	FreeImage_Unload(dib);

	return 0;
}

int XFileManager::XSaveImageAlpha(XOUT unsigned char*& pBuffer, XOUT int& w, XOUT int& h, XIN const char* pFile)
{
	FIBITMAP* dib = FreeImage_Allocate(w, h, 32);
	unsigned char* pPixel = FreeImage_GetBits(dib);
	size_t size = w * h;
	for (unsigned int i = 0; i < size; ++i)
	{
		pPixel[i * 4 + 0] = 0;
		pPixel[i * 4 + 1] = 0;
		pPixel[i * 4 + 2] = 0;
		pPixel[i * 4 + 3] = pBuffer[i];
	}
	FreeImage_Save(FIF_PNG, dib, pFile, PNG_DEFAULT);
	FreeImage_Unload(dib);

	return 0;
}

int XFileManager::XFreeBuffer(XIN unsigned char*& pBuffer)
{
	delete[] pBuffer;
	pBuffer = NULL;
	
	return 0;
}