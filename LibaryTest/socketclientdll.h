
#ifndef _INC_Demo01_H
#define _INC_Demo01_H

#ifdef  __cplusplus
extern "C" {
#endif
	
	int cltSocketInit(void **handle /*out*/); 
	
	int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/);
	
	int cltSocketRev(void *handle /*in*/, unsigned char **buf /*in*/, int *buflen /*in out*/);

	int cltSocketFreeBuf(unsigned char **buf);
	
	int cltSocketDestory(void *handle/*in*/);
	
	
#ifdef  __cplusplus
}
#endif

#endif  /* _INC_Demo01_H */


