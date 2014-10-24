#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue.h"
#include "linklist.h"

typedef struct _tag_linkqueueNode_
{
	LinkListNode node;
	void *item;
}TLinkQueueNode;

LinkQueue* LinkQueue_Create()
{
	return (LinkQueue *)LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue)
{
	if (queue == NULL)
		return;
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
	return;
}

void LinkQueue_Clear(LinkQueue* queue)
{
	if (queue == NULL)
		return;
	while (LinkQueue_Length(queue)>0)
	{
		LinkQueue_Retrieve(queue);
	}

	return;
}

int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	if (queue == NULL || item == NULL)
	{
		return -1;
	}
	TLinkQueueNode *node = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
	if (node == NULL)
	{
		return -2;
	}
	node->item = item;
	ret = LinkList_Insert(queue, (LinkListNode *)node, LinkQueue_Length(queue));
	if (ret != 0)
	{
		free(node);
	}

	return ret;
}

void* LinkQueue_Retrieve(LinkQueue* queue)
{
	if (queue == NULL)
		return NULL;
	
	TLinkQueueNode *node = (TLinkQueueNode *)LinkList_Delete(queue, 0);
	if (node == NULL)
		return NULL;

	void *tmp = node->item;
	free(node);
	return tmp;
}

void* LinkQueue_Header(LinkQueue* queue)
{
	if (queue == NULL)
		return NULL;

	TLinkQueueNode *node = (TLinkQueueNode *)LinkList_Delete(queue, 0);
	if (node == NULL)
		return NULL;

	void *tmp = node->item;
	return tmp;
}

int LinkQueue_Length(LinkQueue* queue)
{
	if (queue == NULL)
		return 0;

	return LinkList_Length(queue);
}
