#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "seqlist.h"

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	unsigned int *node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	TSeqList *ret = NULL;
	if (capacity <= 0 || capacity > 1000)
		return NULL;

	ret = (TSeqList *)malloc(sizeof(TSeqList) + (sizeof(int *)*capacity));
	if (ret == NULL)
	{
		return NULL;
	}
	ret->node = (unsigned int *)(ret + 1);
	ret->length = 0;
	ret->capacity = capacity;

	return (SeqList*)ret;
}

void SeqList_Destroy(SeqList* list)
{
	if (list != NULL)
	{
		free(list);
	}

	return;
}

void SeqList_Clear(SeqList* list)
{
	TSeqList *lst = list;
	if (lst == NULL)
	{
		return;
	}
	
	lst->length = 0;

	return;
}

int SeqList_Length(SeqList* list)
{
	TSeqList *lst = list;
	if(lst == NULL){
		return -1;
	}
	return lst->length;
}

int SeqList_Capacity(SeqList* list)
{	
	TSeqList *lst = list;
	if(lst == NULL){
		return -1;
	}
	return lst->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList *lst = list;
	if (list == NULL || node == NULL)
	{
		return -1;
	}
	if (pos < 0 || pos >= lst->capacity)
	{
		return -2;
	}
	if (lst->length >= lst->capacity)
		return -3;
	
	if (pos >= lst->length)
	{
		pos = lst->length;
	}
	for (int i = lst->length; i > pos; i--)
	{
		lst->node[i] = lst->node[i - 1];
	}
	lst->length++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList *lst = list;
	if (lst == NULL || pos < 0 || pos >= lst->length)
	{
		return NULL;
	}
	SeqListNode * ret = NULL;
	ret = (SeqListNode*)lst->node[pos];

	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList *lst = list;
	SeqListNode *ret = NULL;
	if (lst == NULL || pos < 0 || pos >= lst->length)
	{
		return NULL;
	}
	ret = (SeqListNode *)lst->node[pos];
	for (int i = pos + 1; i < lst->length; i++)
	{
		lst->node[i - 1] = lst->node[i];
	}
	lst->length--;
	return ret;
}
