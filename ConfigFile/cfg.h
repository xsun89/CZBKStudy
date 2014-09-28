#ifndef _CFG_H_
#define _CFG_H_
int readCfg(char *fileName, char *key, int keyLen, char *value, int valueLen);
int writeCfg(char *fileName, char *key, int keyLen, char *value, int valueLen);
#endif // !_CFG_H_
