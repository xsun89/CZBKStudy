#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _binaryTreeNode
{
	int data;
	struct _binaryTreeNode *lptr, *rptr;
}BTreeNode, *BTree;

void preOrder(BTree tree);
void inOrder(BTree tree);
void postOrder(BTree tree);
int treeDepth(BTree tree);
BTree treeCpoy(BTree tree);
void inOrderEx(BTree tree);

#endif