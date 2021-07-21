#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

typedef struct List
{
	struct ListNode* head;
}List;

ListNode* listCreat(LTDataType val)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = val;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void listPrint(List* lst)
{
	assert(lst);
	ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

void listInit(List* lst)
{
	assert(lst);
	lst->head = listCreat(0);
	lst->head->next = lst->head->prev = lst->head;

}

void listDestroy(List* lst)
{
	assert(lst);
	ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(lst->head);
	lst->head = NULL;
}

void listPushBack(List* lst, LTDataType val)
{
	assert(lst);
	// head    °≠°≠  last newNode
	ListNode* newNode = listCreat(val);
	ListNode* last = lst->head->prev;
	last->next = newNode;
	newNode->prev = last;
	newNode->next = lst->head;
	lst->head->prev = newNode;
}
void listPopBack(List* lst)
{
	if (lst == NULL)
	{
		return;
	}
	if (lst->head->next == lst->head)
	{
		return;
	}
	//head °≠°≠  prev last
	ListNode* last = lst->head->prev;
	ListNode* prev = last->prev;
	free(last);
	lst->head->prev = prev;
	prev->next = lst->head;
}

void listPushFront(List* lst, LTDataType val)
{
	assert(lst);
	ListNode* newNode = listCreat(val);
	ListNode*cur = lst->head;
	ListNode*next = cur->next;
	// cur newNode next
	next->prev = newNode;
	newNode->next = next;
	newNode->prev = cur;
	cur->next = newNode;
}


void listPopFront(List* lst)
{
	if (lst == NULL || lst->head->next == lst->head)
	{
		return;
	}
	// head next nextnext
	ListNode* next = lst->head->next;
	ListNode* nextnext = next->next;
	nextnext->prev = lst->head;
	lst->head->next = nextnext;
	free(next);
	next = NULL;
}

void listErase(List* lst, ListNode* pos)
{
	if (lst == NULL || lst->head == pos)
	{
		return;
	}
	//prev pos next
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}


void listInsert(List* lst,ListNode* pos, LTDataType val)
{
	if (lst == NULL)
	{
		return;
	}
	//  prev newNode  pos 
	ListNode* prev = pos->prev;
	ListNode* newNode = listCreat(val);
	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = pos;
	pos->prev = newNode;
}


ListNode* listFind(List* lst, LTDataType val)
{
	assert(lst);
	ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		if (cur->data == val)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	printf("√ª’“µΩ");
	return NULL;
}