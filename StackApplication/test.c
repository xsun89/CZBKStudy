#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[] = "#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0;";
	int ret = grammarAnalyze(str);
	printf("result is %d\n", ret);
	system("pause");
	return 0;
}