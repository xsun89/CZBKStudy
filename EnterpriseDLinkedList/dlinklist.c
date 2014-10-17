#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlinklist.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode *slider;
	int length;
}TDLinkList;

DLinkList* DLinkList_Create()
{
	TDLinkList *ret = (TDLinkList *)malloc(sizeof(TDLinkList));
	if (ret == NULL)
	{
		return NULL;
	}

	ret->header.next = NULL;
	ret->header.pre = NULL;
	ret->length = 0;
	ret->slider = NULL;

	return ret;
}

void DLinkList_Destroy(DLinkList* list)
{
	if (list != NULL)
		free(list);

	return;
}

void DLinkList_Clear(DLinkList* list)
{
	TDLinkList *slist = (TDLinkList *)list;
	if (slist != NULL)
	{
		slist->length = 0;
		slist->header.pre = NULL;
		slist->header.next = NULL;
		slist->slider = NULL;
	}

	return;
}

int DLinkList_Length(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = -1;

	if (sList != NULL)
	{
		ret = sList->length;
	}

	return ret;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	TDLinkList *slist = (TDLinkList *)list;
	if (slist == NULL || node == NULL || pos < 0)
	{
		return -1;
	}
	DLinkListNode *current = (DLinkListNode *)slist;
	DLinkListNode *next = NULL;
	for (int i = 0; (i<pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}
	next = current->next;
	current->next = node;
	node->next = next;
	if (next != NULL)
	{
		next->pre = node;
	}
	if (current == (DLinkListNode *)slist)
		node->pre = NULL;
	else
		node->pre = current;
	if (slist->length == 0)
		slist->slider = node;

	slist->length++;

	return 0;
}