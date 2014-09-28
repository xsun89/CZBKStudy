#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "cfg.h"


#define  DB_sid			"oracle_sid"
#define  DB_User		"appuser"
#define  DB_PassWord	"appuser"
#define	 CFG_FILENAME	"C:/Users/xsun/Source/Repos/CZBKStudy/ItcastCpp/ConfigFile/cfg.ini"

void main_menu()
{
	printf("\n1 Test SetCfgItem(Test set config file)	");
	printf("\n2 Test GetCfgItem(Test read config file)	");
	printf("\n0 exit(0)        (exit)	    ");
	printf("\nplease enter your choice:[1/2/0]: ");
	return;
}


int  Test_SetCfgItem()
{
	int		rv = 0;
	int		choice = 0;

	char	key[1024];
	char	value[1024];

	memset(key, 0, sizeof(key));
	memset(value, 0, sizeof(value));

	printf("\nplease enter key:");
	scanf("%s", key);

	printf("\nplease enter value:");
	scanf("%s", value);

	rv = writeCfg(CFG_FILENAME, key, value, strlen(value));
	if (rv != 0)
	{
		printf("writeCfg err: %d \n", rv);
		goto End;
	}

	printf("write config file test pass\n");

End:
	return rv;

}

int  Test_GetCfgItem()
{
	int		rv = 0;
	int		choice = 0;

	char	key[1024];
	char	value[1024];
	int		valueLen = 1024;

	memset(key, 0, sizeof(key));
	memset(value, 0, sizeof(value));

	printf("\nplease enter key:");
	scanf("%s", key);


	rv = readCfg(CFG_FILENAME, key, value, &valueLen);
	if (rv != 0)
	{
		printf("readCfg err: %d \n", rv);
		goto End;
	}
	printf("\n%s = %s", key, value);

	printf("\nread config file test pass\n");

End:
	return rv;

}

int  main()
{
	int		rv = 0;
	int		choice = 0;

	for (;;)
	{
		main_menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Test_SetCfgItem();   break;
		case 2:
			Test_GetCfgItem();   break;
		case 0:
			exit(0);
		default:
			exit(0);
		}
	}

End:
	return rv;
	getchar();
}


