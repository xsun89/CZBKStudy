#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"
#include "linkstack.h"
typedef struct _tag_LinkStack
{
	LinkListNode node;
	void *item;
}TLinkStackNode;

LinkStack *LinkStack_Create()
{
	return (LinkStack *)LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack)
{
	if (stack == NULL)
		return;
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
}

void LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	while(LinkStack_Size(stack)>0)
	{
		LinkStack_Pop(stack);
	}
	return;
}

int LinkStack_Push(LinkStack* stack, void* item)
{
	if (stack == NULL || item == NULL)
		return -1;
	TLinkStackNode *stackNode = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
	if (stackNode == NULL)
		return -2;
	stackNode->item = item;
	int ret = LinkList_Insert(stack, (LinkListNode *)stackNode, 0);
	if (ret != 0)
		free(stackNode);

	return ret;
}

void* LinkStack_Pop(LinkStack* stack)
{
	if (stack == NULL)
		return NULL;
	TLinkStackNode *stackNode = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if (stackNode == NULL)
		return NULL;

	void *tmp = stackNode->item;
	free(stackNode);
	return tmp;
}

void* LinkStack_Top(LinkStack* stack)
{
	if (stack == NULL)
		return NULL;
	TLinkStackNode *stackNode = (TLinkStackNode *)LinkList_Get(stack, 0);
	void *tmp = stackNode->item;
	return tmp;
}

int LinkStack_Size(LinkStack* stack)
{
	if (stack == NULL)
		return -1;
	return LinkList_Length(stack);
}