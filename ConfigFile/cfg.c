#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg.h"

int readCfg(char *pFileName, char *pKey, char *pValue, int *pValueLen)
{
	int rv = 0;
	FILE *fp = NULL;
	char lineBuf[LineMaxLen] = { 0 };
	char *pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	if (pFileName == NULL || pKey == NULL || pValue == NULL || pValueLen == NULL)
	{
		rv = -1;
		printf("readCfg() error.param err \n");
		goto End;
	}

	fp = fopen(pFileName, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen err. \n");
		goto End;
	}

	while (!feof(fp))
	{
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, LineMaxLen, fp);
		if (pTmp == NULL)
			break;

		pTmp = strchr(lineBuf, '=');
		if (pTmp == NULL)
			continue;
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)
		{
			continue;
		}
		pTmp = strchr(lineBuf, '=');
		if (pTmp == NULL)
		{
			continue;
		}
		pTmp = pTmp + 1;
		while (1)
		{
			if (*pTmp == ' ')
			{
				pTmp++;
			}
			else
			{
				pBegin = pTmp;
				if (*pBegin == '\n')
				{
					printf("config item:%s has no value \n", pKey);
					goto End;
				}
				break;
			}
		}

		while (1)
		{
			if (*pTmp == ' ' || *pTmp == '\n')
				break;
			else
				pTmp++;
		}

		pEnd = pTmp;
		*pValueLen = pEnd - pBegin;
		memcpy(pValue, pBegin, pEnd - pBegin);
		break;
	}
End:
	if (fp != NULL)
		fclose(fp);

	return rv;
}

int writeCfg(char *pFileName, char *pKey, char *pValue, int valueLen)
{
	int rv = 0, iTag = 0, length = 0;
	FILE * fp = NULL;
	char lineBuf[LineMaxLen];
	char *pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char fileBuf[1024 * 8] = { 0 };
	if (pFileName == NULL || pKey == NULL || pValue == NULL)
	{
		rv = -1;
		printf("SetCfgItem() err. param err \n");
		goto End;
	}
	fp = fopen(pFileName, "r+");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}
	fseek(fp, 0L, SEEK_END);
	length = ftell(fp);
	if (length > 1024 * 8)
	{
		rv = -3;
		printf("file exceed 1024*8, nunsupport");
		goto End;
	}
	fseek(fp, 0L, SEEK_SET);

	while (!feof(fp))
	{
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, LineMaxLen, fp);
		if (pTmp == NULL)
			break;

		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)
		{
			strcat(fileBuf, lineBuf);
			continue;
		}
		else
		{
			sprintf(lineBuf, "%s = %s\n", pKey, pValue);
			strcat(fileBuf, lineBuf);
			iTag = 1;
		}
	}

		if (iTag == 0)
		{
			fprintf(fp, "%s = %s\n", pKey, pValue);
		}
		else
		{
			if (fp != NULL)
			{
				fclose(fp);
				fp = NULL;
			}
			fp = fopen(pFileName, "w+t");
			if (fp == NULL)
			{
				rv = -4;
				printf("fopen() err. \n");
				goto End;
			}
			fputs(fileBuf, fp);
		}
End:
	if (fp != NULL) fclose(fp);
	return rv;
}

