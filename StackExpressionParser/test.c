#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[] = "8+(3-1)*5";
	char ret[255] = { 0 };
	transform(str, ret);

	printf("result is %s\n", ret);
	printf("compute result=%d", compute(ret));
	system("pause");
	return 0;
}