#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Node
{
	unsigned id;
	struct Node* next;
} Node, *pNode;


pNode SListCreateHeadInsert();
int SListTraverse(pNode head);
int SListAddNode(pNode head, const int id, const int value);
int SListSort(pNode head);
int SListDestroy(pNode head);
int SListInverse(pNode head);
