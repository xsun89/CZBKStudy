#include "binarytree.h"

void main()
{
	BTreeNode b1, b2, b3, b4, b5;
	memset(&b1, 0, sizeof(BTreeNode));
	memset(&b2, 0, sizeof(BTreeNode));
	memset(&b3, 0, sizeof(BTreeNode));
	memset(&b4, 0, sizeof(BTreeNode));
	memset(&b5, 0, sizeof(BTreeNode));
	b1.data = 1;
	b2.data = 2;
	b3.data = 3;
	b4.data = 4;
	b5.data = 5;

	b1.lptr = &b2;
	b1.rptr = &b3;
	b2.lptr = &b4;
	b3.lptr = &b5;
	printf("\n preorder");
	preOrder(&b1);
	printf("\n inOrderEx");
	inOrderEx(&b1);

	printf("\n inOrder");
	inOrder(&b1);

	printf("\n postOrder");
	postOrder(&b1);
	
	int depth = treeDepth(&b1);

	printf("\n tree depth=%d", depth);
	BTree co = treeCpoy(&b1);
	preOrder(co);

	printf("\n");
	system("pause");
}