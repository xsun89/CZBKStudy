#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg.h"

int readCfg(char *fileName, char *key, int keyLen, char *value, int valueLen)
{
	return 0;
}

int writeCfg(char *fileName, char *key, int keyLen, char *value, int valueLen)
{
	int rv = 0;
	FILE * fp = NULL;
	fp = fopen(fileName, "a");
	if (fp == NULL)
	{
		rv = -2;
		return rv;
	}

	char 
	return 0;
}

int main()
{
	int rv = 0;
	char *fileName = "C:/Users/xsun/Source/Repos/CZBKStudy/ItcastCpp/ConfigFile/cfg.ini";
	char key[100];
	strcpy(key, "oracle");
	int keyLen = strlen(key);
	char value[100] = { "Oracle Value" };
	int valueLen = strlen(value);

	rv = writeCfg(fileName, key, keyLen, value, valueLen);

	return rv;
}