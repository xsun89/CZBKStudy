#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int main()
{
	int a[] = { 12, 3, 56, 67, 1, 89, 2 };
	int len = sizeof(a) / sizeof(*a);
	printf("before sort\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", a[i]);

	}
	//selectSort(a, len);
	//insertSort(a, len);
	bubbleSort(a, len);
	printf("\nafter sort\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}