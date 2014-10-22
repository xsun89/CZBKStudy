#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "linkstack.h"
#include "linklist.h"

typedef struct _tag_LinkStackNode
{
	LinkListNode node;
	void *item;
}TLinkStackNode;

LinkStack* LinkStack_Create()
{

	return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
	return ;
}


void LinkStack_Clear(LinkStack* stack)
{
	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);
	}
	return ;
}

int LinkStack_Push(LinkStack* stack, void* item)
{
	int ret = 0;
	TLinkStackNode *node = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
	if (node == NULL || item == NULL)
	{
		return -1;
	}
	node->item = item;
	ret = LinkList_Insert(stack, (LinkListNode*)node, 0);
	if (ret != 0)
	{
		free(node);
	}
	return ret;
}


void* LinkStack_Pop(LinkStack* stack)
{
	void *ret = NULL;
	TLinkStackNode *node = NULL;
	if (stack == NULL)
	{
		return NULL;
	}
	node = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if (node == NULL)
	{
		return NULL;
	}
	ret = node->item;

	//注意 释放内存不要忘记
	if (node != NULL) 
	{
		free(node);
	}

	return ret;
}

void* LinkStack_Top(LinkStack* stack)
{
	void *ret = NULL;
	TLinkStackNode *node = NULL;
	if (stack == NULL)
	{
		return NULL;
	}
	node = (TLinkStackNode *)LinkList_Get(stack, 0);
	if (node == NULL)
	{
		return NULL;
	}
	ret = node->item;
	return ret;
}

int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}


