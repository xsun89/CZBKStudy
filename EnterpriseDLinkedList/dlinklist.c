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

DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	TDLinkList *slist = list;
	if (slist == NULL || pos < 0 || pos >= slist->length)
	{
		return NULL;
	}
	DLinkListNode *current = NULL;
	current = (DLinkListNode *)slist;
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	return current->next;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	TDLinkList *slist = list;
	DLinkListNode *ret = NULL;
	if (slist == NULL || pos < 0 || pos >= slist->length)
	{
		return NULL;
	}
	DLinkListNode *current = NULL;
	current = (DLinkListNode *)slist;
	DLinkListNode *next = NULL;
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	ret = current->next;
	next = ret->next;
	current->next = next;
	if (next != NULL)
	{
		next->pre = current;

		if (current == (DLinkListNode *)slist)
		{
			next->pre = NULL;
		}
	}

	if (slist->slider == ret)
	{
		slist->slider = next;
	}
	slist->length--;
	return next;

}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	TDLinkList *slist = list;
	DLinkListNode *ret = NULL;
	int i;
	if (slist == NULL || node == NULL)
	{
		return NULL;
	}

	DLinkListNode *current = (DLinkListNode *)slist;
	for (i = 0; i < slist->length; i++)
	{
		if (current->next == node)
		{
			ret = current->next;
			break;
		}
		current = current->next;
	}
	if (ret != NULL)
		DLinkList_Delete(slist, i);

	return ret;
}

DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	TDLinkList *slist = list;
	DLinkListNode *ret = NULL;
	if (slist == NULL)
		return NULL;
	slist->slider = slist->header.next;
	ret = slist->slider;
	return ret;
}

DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList *slist = list;
	DLinkListNode *ret = NULL;
	if (slist == NULL)
		return NULL;
	ret = slist->slider;
	return ret;
}

DLinkListNode* DLinkList_Next(DLinkList* list)
{
	TDLinkList *slist = list;
	DLinkListNode *ret = NULL;
	if (slist == NULL || slist->slider == NULL)
		return NULL;
	ret = slist->slider;
	slist->slider = ret->next;
	return ret;
}

DLinkListNode* DLinkList_Pre(DLinkList* list)
{
	TDLinkList *slist = list;
	DLinkListNode *ret = NULL;
	if (slist == NULL || slist->slider == NULL)
		return NULL;
	ret = slist->slider;
	slist->slider = ret->pre;
	return ret;
}
