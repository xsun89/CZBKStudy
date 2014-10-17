#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Mylinklist.h"

int main()
{
	int ret = 0;
	LinkList *list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 1;
	t2.age = 2;
	t3.age = 3;
	t4.age = 4;
	t5.age = 5;
	list = LinkList_Create();
	int listLen = LinkList_Length(list);
	LinkList_Insert(list, (LinkListNode *)&t1, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t2, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t3, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t4, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode *)&t5, LinkList_Length(list));

	for (int i = 0; i < LinkList_Length(list); i++)
	{
		Teacher *t = (Teacher *)LinkList_Get(list, i);
		printf("age = [%d]\n", t->age);
	}
	LinkList_Destroy(list);
	system("pause");
	return ret;
}