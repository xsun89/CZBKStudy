#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int combinAndSort(char **fisrt, int firstLen, char(*second)[30], int secondLen, char ***out, int *outLen)
{
	int ret = 0;
	if (fisrt == NULL || second == NULL)
	{
		ret = -1;
		return ret;
	}
	int totalLen = firstLen + secondLen;
	char **temp = (char *)malloc(totalLen*sizeof(char *));
	memset(temp, 0, totalLen*sizeof(char *));
	int i=0, j=0;
	for (i = 0; i < totalLen; i++)
	{
		temp[i] = (char *)malloc(100 * sizeof(char));
		if (temp[i] == NULL)
		{
			ret = -2;
			return ret;
		}

		memset(temp[i], 0, 100 * sizeof(char));
	}
	for (i = 0; i < firstLen; i++)
	{
		strcpy(temp[i], fisrt[i]);
	}

	for (j = 0; j < secondLen; i++, j++)
	{
		strcpy(temp[i], second[j]);
	}

	for (i = 0; i < totalLen; i++)
	{
		for (j = i + 1; j < totalLen; j++)
		{
			char *buf = NULL;
			if (*temp[i] < *temp[j])
			{
				buf = temp[i];
				temp[i] = temp[j];
				temp[j] = buf;
			}
		}
	}
	*out = temp;
	*outLen = totalLen;
	return ret;

}
int main()
{
	int ret = 0;
	char *firstArray[] = {"bbbbb", "aaaaa", "ccccc", "22222", "11111", "44444" };
	char secondArray[10][30] = { "zzzz", "yyyy", "333333" };

	char **out = NULL;
	int outLen = 0;

	ret = combinAndSort(firstArray, 6, secondArray, 3, &out, &outLen);

	for (int i = 0; i < outLen; i++)
	{
		printf("%s\n", *(out+i));
	}
	if (out != NULL)
	{
		for (int j = 0; j < outLen; j++)
		{
			if (out[j] != NULL)
			{
				free(out[j]);
			}
		}

		free(out);
	}
	system("pause");
	return ret;
}