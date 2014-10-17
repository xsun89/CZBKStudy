
#ifndef _INC_Demo01_H
#define _INC_Demo01_H

#ifdef  __cplusplus
extern "C" {
#endif
	typedef int(*EncData)(unsigned char *inData, int inDataLen, unsigned char *outData, int *outDataLen, void *Ref, int RefLen);
	typedef int(*DecData)(unsigned char *inData, int inDataLen, unsigned char *outData, int *outDataLen, void *Ref, int RefLen);

	int cltSocketInit(void **handle /*out*/); 
	
	int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/);
	
	int cltSocketRev(void *handle /*in*/, unsigned char **buf /*in*/, int *buflen /*in out*/);

	int cltSocketFreeBuf(unsigned char **buf);
	
	int cltSocketDestory(void *handle/*in*/);

	int clitSocket_setEncFunc(void *handle, EncData encDataCallback, void *ref, int refLen);
	
	
#ifdef  __cplusplus
}
#endif

#endif  /* _INC_Demo01_H */


