#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct _Node
{
	int data;
	struct _Node *next;
}Node;
int destroyList(Node *head);
int createList(Node **head);
int printList(Node *head);
int insertNode(Node *head, int x, int y);
int deletNode(Node *head, int x);
int reverseList(Node *head);

int createList(Node **head)
{
	int ret = 0;
	Node *pHead = NULL;
	pHead = (Node *)malloc(sizeof(Node));
	if (pHead == NULL)
	{
		ret = -1;
		return ret;
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
			destroyList(pHead);
			ret = -2;
			return ret;
		}
		pMal->data = data;
		pMal->next = NULL;

		pCur->next = pMal;
		pCur = pMal;
		printf("Please input data\n");
		scanf("%d", &data);
	}
	*head = pHead;
	return ret;
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

int destroyList(Node *head)
{
	int ret = 0;
	if (head == NULL)
	{
		ret = -1;
		return ret;
	}
	Node *pCur = NULL;
	Node *pTmp = NULL;
	pCur = head;
	while (pCur)
	{
		pTmp = pCur->next;
		free(pCur);
		pCur = pTmp;
	}

	return ret;
}

int insertNode(Node *head, int x, int y)
{
	int ret = 0;
	if (head == NULL)
	{
		ret = -1;
		return ret;
	}

	Node *pPre = NULL;
	Node *pCur = NULL;
	Node *pMal = NULL;

	pPre = head;
	pCur = pPre->next;
	while (pCur)
	{
		if (pCur->data == x)
		{
			break;
		}
		pPre = pCur;
		pCur = pPre->next;
	}

	pMal = (Node *)malloc(sizeof(Node));
	pMal->data = y;

	pMal->next = pPre->next;
	pPre->next = pMal;

	return ret;
}

int deletNode(Node *head, int x)
{	
	int ret = 0;
	if (head == NULL)
	{
		ret = -1;
		return ret;
	}

	Node *pPre = NULL;
	Node *pCur = NULL;

	pPre = head;
	pCur = pPre->next;
	while (pCur)
	{
		if (pCur->data == x)
		{
			break;
		}
		pPre = pCur;
		pCur = pPre->next;
	}
	if (pCur == NULL)
	{
		ret = -2;
		printf("node x=%d is not found\n", x);
		return ret;
	}

	pPre->next = pCur->next;
	free(pCur);

	return ret;
	
}

int reverseList(Node *head)
{
	int ret = 0;
	if (head == NULL)
	{
		ret = -1;
		return ret;
	}
	Node *pCur = NULL, *pPre = NULL, *pTmp = NULL;
	pPre = head->next;
	pCur = pPre->next;
	if (pPre == NULL || pCur == NULL)
	{
		ret = 0;
		return ret;
	}

	while (pCur)
	{
		pTmp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pTmp;
	}

	head->next->next = NULL;
	head->next = pPre;

	return ret;
	
}

int main()
{
	int ret = 0;
	Node *head = NULL;
	ret = createList(&head);
	ret = printList(head);
	ret = reverseList(head);
	ret = printList(head);
	ret = destroyList(head);
	system("pause");

	return ret;
}