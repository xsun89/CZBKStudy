#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
} TCircleList;

CircleList* CircleList_Create()
{
	TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
	if (ret == NULL)
	{
		return NULL;
	}

	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;

	return ret;
}

void CircleList_Destroy(CircleList* list)
{
	if (list == NULL)
	{
		return;
	}

	free(list);
}

void CircleList_Clear(CircleList* list)
{
	TCircleList *slist = (TCircleList *)list;
	if (slist == NULL)
		return;

	slist->length = 0;
	slist->header.next = NULL;
	slist->slider = NULL;
}

int CircleList_Length(CircleList* list) // O(1)
{
	TCircleList* sList = (TCircleList*)list;
	int ret = -1;
	if (list == NULL)
	{
		return ret;
	}
	ret = sList->length;
	return ret;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	int ret = 0;
	TCircleList *slist = (TCircleList *)list;
	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}
	CircleListNode *current = &slist->header;
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	if (slist->length == 0)
	{
		slist->slider = node;
	}
	if (current == (CircleListNode *)slist)
	{
		node->next = current->next;
	}
	slist->length++;
	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	TCircleList *slist = list;
	CircleListNode * ret = NULL;
	if (slist == NULL || pos < 0)
	{
		return NULL;
	}
	CircleListNode *current = (CircleListNode *)slist;
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	ret = current->next;
	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	TCircleList *slist = (TCircleList *)list;
	if (slist == NULL || pos < 0 || slist->length <= 0)
	{
		return NULL;
	}
	CircleListNode *current = (CircleListNode *)slist;
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	CircleListNode *last = NULL;
	if (current == (CircleListNode *)slist)
	{
		last = (CircleListNode *)CircleList_Get(slist, slist->length - 1);
	}
	CircleListNode *ret = current->next;
	current->next = ret->next; 
	slist->length--;
	// delete the first node
	if (last != NULL)
	{
		slist->header.next = ret->next;
		last->next = ret->next;
	}
	if (slist->slider == ret)
	{
		slist->slider = ret->next;
	}

	if (slist->length == 0)
	{
		slist->header.next = NULL;
		slist->slider = NULL;
	}

	return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TCircleList *slist = list;
	CircleListNode *ret = NULL;
	if (slist == NULL || node == NULL)
		return NULL;

	CircleListNode *current = (CircleListNode *)slist;
	int i;
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
		CircleList_Delete(slist, i);

	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList *slist = list;
	if (slist == NULL)
		return NULL;

	slist->slider = slist->header.next;
	CircleListNode *ret = NULL;
	ret = slist->slider;
	return ret;
}

CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList *slist = list;
	if (slist == NULL)
		return NULL;

	CircleListNode *ret = NULL;
	ret = slist->slider;
	return ret;
}

CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList *slist = list;
	if (slist == NULL || slist->slider == NULL)
		return NULL;

	CircleListNode *ret = NULL;
	ret = slist->slider;
	slist->slider = ret->next;
	return ret;
}