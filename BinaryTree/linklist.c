#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create() //O(1)
{
	TLinkList *ret = (TLinkList *)malloc(sizeof(TLinkList));
	if (ret == NULL)
	{
		return ret;
	}
	ret->header.next = NULL;
	ret->length = 0;
	return ret;
}

void LinkList_Destroy(LinkList* list) //O(1)
{
	if (list != NULL)
	{
		free(list);
	}
	return ;
}

void LinkList_Clear(LinkList* list) //O(1)
{
	TLinkList *tlist = list;
	if (tlist == NULL)
	{
		return;
	}
	tlist->header.next = NULL;
	tlist->length = 0;
	return ;
}

int LinkList_Length(LinkList* list) //O(1)
{
	TLinkList *tlist = list;
	if (tlist == NULL)
	{
		return -1;
	}
	return tlist->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)  //O(n)
{
	LinkListNode *current = NULL;
	int i = 0;
	TLinkList *tlist = list;
	if (list==NULL || node==NULL || pos<0)
	{
		return -1;
	}
	current = (LinkListNode *)tlist;
	for (i=0; (i<pos)&&(current->next!=NULL); i++)
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tlist->length++;
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)  //O(n)
{
	LinkListNode *current = NULL;
	LinkListNode *ret = NULL;
	int i = 0;
	TLinkList *tlist = list;
	if (list==NULL || pos<0)
	{
		return NULL;
	}
	
	current = (LinkListNode *)tlist;
	for (i=0; i<pos; i++)
	{
		current = current->next;
	}
	ret = current->next;

	return ret;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)  //O(n)
{
	int i = 0;
	LinkListNode *ret = NULL;
	LinkListNode *current = NULL;
	TLinkList *tlist = list;
	if (list == NULL || pos<0)
	{
		return NULL;
	}
	current = (LinkListNode *)tlist;
	for (i=0; i<pos; i++)
	{
		current = current->next;
	}
	//做了一个缓存 把位置元素缓存下来
	ret = current->next;

	//执行删除操作
	current->next = ret->next;
	tlist->length --;

	return ret;
}