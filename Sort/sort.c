#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void selectSort(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int k = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		int tmp = a[i];
		a[i] = a[k];
		a[k] = tmp;
	}

	return;
}

void insertSort(int a[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int k = i;
		int tmp = a[k];
		for (int j = i-1; j >= 0; j--)
		{
			if (a[j] > tmp)
			{
				a[j+1] = a[j];
				k = j;
			}
		}
		a[k] = tmp;
	}
	return;
}

void bubbleSort(int *a, int len)
{
	int tmp = -1;
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < len-i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}