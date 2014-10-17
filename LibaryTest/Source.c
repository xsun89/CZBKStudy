#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "socketclientdll.h"
#include "itcastlog.h"

int MyEncData(unsigned char *inData, int inDataLen, unsigned char *outData, int *outDataLen, void *Ref, int RefLen)
{
	memcpy(outData, "111111111111111111111111111111111", 10);
	*outDataLen = 10;
	return 0;
}

int main()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char buf[30] = { 0 };
	ret = cltSocketInit(&handle) ;
	if (ret != 0)
	{
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "err on cltSocketInit()\n");
		goto End;
	}
	ret = clitSocket_setEncFunc(handle, MyEncData, NULL, 0);
	if (ret != 0)
	{
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "err on clitSocket_setEncFunc()\n");
		goto End;
	}
	strcpy(buf, "abcdefghijklmn");
	ret = cltSocketSend(handle, buf, strlen(buf));
	if (ret != 0)
	{
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "err on cltSocketSend()\n");
		goto End;
	}

	unsigned char *retBuf = NULL;
	int retBufLen = 0;
	ret = cltSocketRev(handle, &retBuf, &retBufLen);
	if (ret != 0)
	{
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "err on cltSocketSend()\n");
		goto End;
	}
	printf("retBuf = [%s] and length = [%d]\n", retBuf, retBufLen);
	ret = cltSocketFreeBuf(&retBuf);
	if (ret != 0)
	{
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "err on cltSocketFreeBuf()\n");
		goto End;
	}
End:
	if (handle != NULL)
	{
		cltSocketDestory(&handle/*in*/);
	}
	system("pause");

	return ret;
}