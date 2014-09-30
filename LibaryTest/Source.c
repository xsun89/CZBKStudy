#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "socketclientdll.h"

void main()
{
	int ret = 0;
	void *handle = NULL;

	ret = cltSocketInit(&handle);

	system("pause");

	return;
}