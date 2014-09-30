#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct _SCK_HANDLE {
	char version[16];
	char serverip[16];
	int serverport;
	char *pBuf;
	int buflen;
}SCK_HANDLE;

__declspec(dllexport)
int cltSocketInit(void **handle)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	sh = (SCK_HANDLE*)malloc(sizeof(SCK_HANDLE));
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
	sh->pBuf = (char*)malloc(buflen*sizeof(char));
	if (sh->pBuf == NULL)
	{
		ret = -2;
		return ret;
	}
	memcpy(sh->pBuf, buf, buflen);
	sh->buflen = buflen;
	return ret;
}

__declspec(dllexport)
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL || buf == NULL || buflen == NULL)
	{
		ret = -1;
		return ret;
	}
	sh = handle;
	memcpy(buf, sh->pBuf, sh->buflen);
	*buflen = sh->buflen;

	return ret;
}

__declspec(dllexport)
int cltSocketDestory(void *handle/*in*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL)
	{
		ret = -1;
		return ret;
	}

	sh = (SCK_HANDLE *)handle;
	if (sh->pBuf != NULL)
		free(sh->pBuf);

	free(sh);
	return ret;
}