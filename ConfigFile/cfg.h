#ifndef _CFG_H_
#define _CFG_H_

#define  LineMaxLen 2048
#define  KeyMaxLen 64

int readCfg(char *pFileName, char *pKey, char *pValue, int *pValueLen);
int writeCfg(char *pFileName, char *pKey, char *pValue, int valueLen);

#endif // !_CFG_H_
