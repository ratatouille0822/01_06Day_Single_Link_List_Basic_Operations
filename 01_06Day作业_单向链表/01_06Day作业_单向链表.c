#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList_Funcs.h"


int main(void)
{
	pNode head = NULL;

	head = SListCreateHeadInsert();
	int len = SListTraverse(head);
	printf("The length of list is %d\n", len);
	printf("Insert node ID = 4, value = 500\n");
	SListInverse(head);
	SListTraverse(head);
	SListAddNode(head, 4, 500);
	len = SListTraverse(head);
	printf("The length of list is %d\n", len);

	SListSort(head);
	SListTraverse(head);


	SListDestroy(head);
	printf("\n");
	system("pause");
	return 0;
}
