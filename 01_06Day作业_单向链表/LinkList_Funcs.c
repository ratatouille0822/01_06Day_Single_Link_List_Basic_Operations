#include "LinkList_Funcs.h"


pNode SListCreateHeadInsert()
{
	pNode head = (pNode)malloc(sizeof(Node));
	if (NULL == head)
	{
		perror("Error Creating Head!\n");
		return -1;
	}
	head->id = 0;
	head->next = NULL;

	pNode p = NULL;

	int num = 0;

	while (1)
	{
		scanf("%d", &num);
		if (-1 == num)
		{
			break;
		}

		p = (pNode)malloc(sizeof(Node));
		if (NULL == p)
		{
			perror("Error creating new node!\n");
			return -2;
		}
		p->id = num;
		p->next = head->next;
		head->next = p;
		printf("Node ID = %d, Next is %p, Addr is %p\n", p->id, p->next, p);

	}
	return head;
}

int SListTraverse(pNode head)
{
	pNode p = head->next;
	unsigned cnt = 0;
	while (NULL != p)
	{
		printf("%d -->", p->id);
		p = p->next;
		++cnt;
	}
	printf("\n");
	return cnt;
}

int SListAddNode(pNode head, const int id, const int value)
{
	pNode p = (pNode)malloc(sizeof(Node));
	
	pNode pCurrent, pPre;
	pCurrent = head->next;
	pPre = head;

	char flag = 0;
	while (NULL != pCurrent)
	{
		if (pCurrent->id == id)
		{
			p->id = value;
			pPre->next = p;
			p->next = pCurrent;
			flag = 1;
		}
		pPre = pPre->next;
		pCurrent = pCurrent->next;
	}
	if (1 == flag)
	{
		printf("Insert Succeed!\n");
		return 0;
	}
	else
	{
		printf("No node with ID = 1\n");
		return -1;
	}
}

int SListSort(pNode head)
{
	pNode p1 = NULL;
	pNode p2 = NULL;
	for (p1 = head->next; p1->next != NULL; p1 = p1->next)
	{
		for (p2 = p1->next; p2 != NULL; p2 = p2->next)
		{
			if (p1->id > p2->id)
			{
				Node temp = *p1;
				*p1 = *p2;
				*p2 = temp;

				pNode pTmp = p1->next;
				p1->next = p2->next;
				p2->next = pTmp;
			}
		}
	}
	return 0;
}

int SListDestroy(pNode head)
{
	printf("destroy link list\n");
	pNode p = head;
	while (p != NULL)
	{
		printf("Free %p, ID is %d\n", p, p->id);
		pNode Tmp;
		Tmp = p->next;
		free(p);
		p = Tmp;
	}
	return 0;
}

int SListInverse(pNode head)
{
	pNode p;

	p = head->next;
	pNode Temp = head->next;
	pNode p1, p2,p3;
	p1 = head->next;
	p2 = head->next->next;
	p3 = head->next;
	Temp->next = NULL;
	
	
	while (NULL != p1->next)
	{

		p1 = p1->next;
		p2 = p2->next;
		p2->next = p3;
		p3 = p2;
	}
	p1->next = head;

	return 0;
}
