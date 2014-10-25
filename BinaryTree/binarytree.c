#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"
#include "linkstack.h"

void preOrder(BTree tree)
{
	if (tree == NULL)
		return;

	printf("\n%d", tree->data);
	preOrder(tree->lptr);
	preOrder(tree->rptr);
}
void inOrder(BTree tree)
{
	if (tree == NULL)
		return;

	inOrder(tree->lptr);
	printf("\n%d", tree->data);
	inOrder(tree->rptr);
}

void postOrder(BTree tree)
{
	if (tree == NULL)
		return;

	postOrder(tree->lptr);
	postOrder(tree->rptr);
	printf("\n%d", tree->data);
}

int treeDepth(BTree tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	int ldepth = treeDepth(tree->lptr);
	int rdepth = treeDepth(tree->rptr);
	if (ldepth > rdepth)
	{
		return ldepth + 1;
	}
	else
	{
		return rdepth + 1;
	}
}

BTree treeCpoy(BTree tree)
{
	if (tree == NULL)
		return NULL;
	BTreeNode *newnode = NULL, *newlptr = NULL, *newrptr = NULL;
	newnode = (BTreeNode *)malloc(sizeof(BTreeNode));
	if (newnode == NULL)
		return NULL;
	if (tree->lptr != NULL)
		newlptr = treeCpoy(tree->lptr);
	else
		newlptr = NULL;

	if (tree->rptr != NULL)
		newrptr = treeCpoy(tree->rptr);
	else
		newrptr = NULL;
	
	newnode->data = tree->data;
	newnode->lptr = newlptr;
	newnode->rptr = newrptr;

	return newnode;
}

BTree lastLeftNode(BTree tree, LinkStack *stack)
{
	if (tree == NULL || stack == NULL)
		return NULL;
	while (tree->lptr)
	{
		LinkStack_Push(stack, (void *)tree);
		tree = tree->lptr;
	}

	return tree;
}

void inOrderEx(BTree tree)
{
	if (tree == NULL)
		return;

	LinkStack *stack = LinkStack_Create();
	BTree t = lastLeftNode(tree, stack);
	while (t != NULL)
	{
		printf("\n%d", t->data);
		if (t->rptr != NULL)
		{
			t = lastLeftNode(t->rptr, stack);
		}
		else if (LinkStack_Size(stack) > 0)
		{
			t = (BTreeNode *)LinkStack_Pop(stack);
		}
		else
		{
			t = NULL;
		}
	}

	return;
}