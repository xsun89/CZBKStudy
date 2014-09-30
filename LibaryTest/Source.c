#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "socketclientdll.h"
#include "itcastlog.h"

int main()
{
	int ret = 0;
	void *handle = NULL;
	unsigned char buf[30] = { 0 };
	ret = cltSocketInit(&handle) ;
	if (ret != 0)
	{
		ITCAST_LOG(__FILE__, __LINE__, 4, 0, "err on cltSocketInit()\n");
		goto End;
	}
	strcpy(buf, "abcdefghijklmn");
	ret = cltSocketSend(handle, buf, strlen(buf));
	if (ret != 0)
	{
		ITCAST_LOG(__FILE__, __LINE__, 4, 0, "err on cltSocketSend()\n");
		goto End;
	}

	char retBuf[30];
	int retBufLen = 0;
	memset(retBuf, 0, sizeof(retBuf));
	ret = cltSocketRev(handle, retBuf, &retBufLen);
	if (ret != 0)
	{
		ITCAST_LOG(__FILE__, __LINE__, 4, 0, "err on cltSocketSend()\n");
		goto End;
	}
	printf("retBuf = [%s] and length = [%d]\n", retBuf, retBufLen);
End:
	if (handle != NULL)
	{
		cltSocketDestory(handle/*in*/);
	}
	system("pause");

	return ret;
}