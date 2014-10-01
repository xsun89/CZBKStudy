#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct _Node
{
	int data;
	struct _Node *next;
}Node;

Node *createList()
{
	int ret = 0;
	Node *pHead = NULL;
	pHead = (Node *)malloc(sizeof(Node));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;
	Node *pCur = pHead;
	printf("Please input data\n");
	int data = 0;
	scanf("%d", &data);
	while (data != -1)
	{
		Node *pMal = (Node *)malloc(sizeof(Node));
		if (pMal == NULL)
		{
			return NULL;
		}
		pMal->data = data;
		pMal->next = NULL;

		pCur->next = pMal;
		pCur = pMal;
		printf("Please input data\n");
		scanf("%d", &data);
	}
	return pHead;
}

int printList(Node *head)
{
	int ret = 0;
	if (head == NULL)
	{
		ret = -1;
		return ret;
	}
	Node *p = head->next;
	while (p)
	{
		printf("%d \n", p->data);
		p = p->next;
	}

	return ret;
}


int main()
{
	int ret = 0;
	Node *head = NULL;
	head = createList();
	ret = printList(head);
	system("pause");

	return ret;
}