#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "SlistNode.h"
SListNode* creatListNode(SLTDataType val)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	if (node == NULL)
	{
		printf("ÉêÇëÊ§°Ü£¡\n");
		exit(-1);
	}
	node->data = val;
	node->next = NULL;
	return node;
}

void SListPrint(SListNode* plist)
{
	while (plist)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pphead, SLTDataType val)
{
	SListNode* newNode = creatListNode(val);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	SListNode* tail = *pphead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newNode;
}

void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->next == NULL){
		free(*pphead);
		*pphead = NULL;
	}
	SListNode* tail = *pphead;
	SListNode* prev = NULL;
	while (tail->next != NULL){
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	prev->next = NULL; 
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	// pos  next  nextnext
	//É¾³ýnextÎ»ÖÃµÄÊý¾Ý
	if (pos->next != NULL)
	{
		SListNode* next = pos->next;
		SListNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}
}


void SListInsertAfter(SListNode* pos, SLTDataType val)
{
	assert(pos);
	//pos         next
	//pos newnode next
	SListNode* next = pos->next;
	SListNode* newNode = creatListNode(val);
	pos->next = newNode;
	newNode->next = next;
}

SListNode* SListFind(SListNode* phead, SLTDataType val)
{
	SListNode* cur = phead;
	while (cur)
	{
		if (cur->data == val)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListPushFront(SListNode** pphead, SLTDataType val)
{
	SListNode* newNode = creatListNode(val);
	newNode->next =*pphead;
	*pphead = newNode;
}

void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}


int listSize(SListNode** pphead)
{
	int count = 0;
	SListNode* tail = *pphead;
	while (tail->next != NULL)
	{
		tail = tail->next;
		count++;
	}
	return count;
}



void listDestory(SListNode** pphead)
{
	assert(pphead);
	SListNode* cur = *pphead;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

