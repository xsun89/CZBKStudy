#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linklist.h"
typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList *head = NULL;
	head = (TLinkList *)malloc(sizeof(TLinkList));
	if (head == NULL)
	{
		return NULL;
	}
	head->header.next = NULL;
	head->length = 0;
	return (LinkList *)head;
}

void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
		free(list);

	return;
}

void LinkList_Clear(LinkList* list)
{
	TLinkList *lst = list;
	if (lst == NULL)
		return;

	lst->header.next = NULL;
	lst->length = 0;

	return;
}

int LinkList_Length(LinkList* list)
{
	TLinkList *lst = list;
	if (lst == NULL)
		return -1;

	return lst->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList *lst = list;
	if (lst == NULL || node == NULL || pos <0)
	{
		return -1;
	}
	LinkListNode *current = NULL;
	current = (LinkListNode *)lst;
	for (int i = 0; (i<pos) && (current->next != NULL); i++); 
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	lst->length++;

	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{

}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{

}