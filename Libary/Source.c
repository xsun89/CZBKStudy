#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int(*EncData)(unsigned char *inData, int inDataLen, unsigned char *outData, int *outDataLen, void *Ref, int RefLen);
typedef int(*DecData)(unsigned char *inData, int inDataLen, unsigned char *outData, int *outDataLen, void *Ref, int RefLen);

typedef struct _SCK_HANDLE {
	char version[16];
	char serverip[16];
	int serverport;
	unsigned char *pBuf;
	int buflen;
	EncData encData;
	void *encRef;
	int encRefLen;
	DecData decData;
	void *decRef;
	int decRefLen;
}SCK_HANDLE;

__declspec(dllexport)
int cltSocketInit(void **handle)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	sh = (SCK_HANDLE*)malloc(sizeof(SCK_HANDLE));
	memset(sh, 0, sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		ret = -1;
		return ret;
	}
	strcpy(sh->version, "1.0.0");
	strcpy(sh->serverip, "192.168.0.100");
	sh->serverport = 8080;

	*handle = sh;
	return ret;
}

__declspec(dllexport)
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL || buf == NULL || buflen > 5 * 1024)
	{
		ret = -1;
		return ret;
	}

	sh = (SCK_HANDLE *)handle;
	sh->pBuf = (unsigned char*)malloc(buflen*sizeof(unsigned char)+ 128);
	memset(sh->pBuf, 0, buflen*sizeof(unsigned char) + 128);
	if (sh->pBuf == NULL)
	{
		ret = -2;
		return ret;
	}
	if (sh->encData != NULL)
	{
		ret = sh->encData(buf, buflen, sh->pBuf, &sh->buflen, sh->encRef, sh->encRefLen);
		if (ret != 0)
		{
			return ret;
		}

	}
	else
	{
		memcpy(sh->pBuf, buf, buflen);
		sh->buflen = buflen;
	}
	return ret;
}

__declspec(dllexport)
int cltSocketRev(void *handle /*in*/, unsigned char **buf /*in*/, int *buflen /*in out*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL || buf == NULL || buflen == NULL)
	{
		ret = -1;
		return ret;
	}
	sh = handle;
	unsigned char *tmp = (unsigned char*)malloc(sh->buflen*sizeof(char));
	memcpy(tmp, sh->pBuf, sh->buflen);
	*buf = tmp;
	*buflen = sh->buflen;

	return ret;
}

__declspec(dllexport)
int cltSocketFreeBuf(unsigned char **buf)
{
	int ret = 0;
	if (buf == NULL)
	{
		ret = -1;
		return ret;
	}
	
	if (*buf != NULL)
		free(*buf);

	*buf = NULL;

	return ret;
}

__declspec(dllexport)
int cltSocketDestory(void **handle/*in*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL)
	{
		ret = -1;
		return ret;
	}

	sh = (SCK_HANDLE *) *handle;
	if (sh == NULL)
	{
		ret = -2;
		return ret;
	}
	if (sh->pBuf != NULL)
		free(sh->pBuf);

	if (sh->encRef != NULL)
		free(sh->encRef);

	if (sh->decRef != NULL)
		free(sh->decRef);

	free(sh);

	*handle = NULL;
	return ret;
}

__declspec(dllexport)
int clitSocket_setEncFunc(void *handle, EncData encDataCallback, void *ref, int refLen)
{
	SCK_HANDLE *sh = NULL;
	sh = handle;
	if (sh == NULL)
	{
		return -1;
	}

	sh->encData = encDataCallback;
	if (refLen > 0)
	{
		sh->encRef = (void *)malloc(refLen);
		if (sh->encRef == NULL)
		{
			return -2;
		}
		memcpy(sh->encRef, ref, refLen);
		sh->encRefLen = refLen;
	}

	return 0;
}