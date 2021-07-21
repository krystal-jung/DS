#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int LDataType;
typedef struct listNode{
	LDataType data;
	struct listNode* next;
}listNode;

typedef struct list{
	listNode* head;
}list;
//初始化
void listInit(list* lst){
	if (lst == NULL){
		return;
	}
	lst->head = NULL;
}
//尾插
listNode* creatNode(LDataType val){
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->data = val;
	node->next = NULL;
	return node;
}
void listPushBack(list* lst,LDataType val){
	if (lst == NULL){
		return;
	}
	if (lst->head == NULL){
		//创建节点
		lst->head=creatNode(val);
	}
	else{
		//遍历找到最后一个节点
		listNode* tail = lst->head;
		while (tail->next != NULL){
			tail = tail->next;
		}
		//插入
		tail->next = creatNode(val);

	}
}


void listPopBack(list* lst){
	if (lst == NULL || lst->head == NULL){
		return;
	}
	listNode* tail = lst->head;
	listNode* prev = NULL;
	while (tail->next != NULL){
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	if (prev == NULL){//删除头结点
		lst->head = NULL;
	}
	else{
		prev->next = NULL;
	}
}

void listPushFront(list* lst ,LDataType val){
	if (lst == NULL){
		return;
	}
	if (lst->head == NULL){
		lst->head = creatNode(val);
	}
	else{
		listNode* node = creatNode(val);
		listNode* next = lst->head;
		lst->head = node;
		node->next = next;
	}
}

void listPopFront(list* lst){
	if (lst == NULL || lst->head == NULL){
		return;
	}
	listNode* next = lst->head->next;
	free(lst->head);
	lst->head = next;

}

void listInsertAfter(listNode* cur, LDataType val){
	listNode* node = creatNode(val);
	listNode* next = cur->next;
	cur->next = node;
	node->next = next;
}

void listEraseAfter(listNode* cur){
	listNode* next = cur->next;
	if (next == NULL){
		return;
	}
	else{
		listNode* nextnext = next->next;
		free(next);
		cur->next = nextnext;
	}
}

listNode* listFind(list* lst, LDataType val){
	if (lst == NULL || lst->head == NULL){
		return NULL;
	}
	listNode* cur = lst->head;
	while (cur){
		if (cur->data == val){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

int listSize(list* lst){
	int count = 0;
	listNode* tail = lst->head;
	while (tail->next != NULL){
		tail = tail->next;
		count++;
	}
	return count;
}

void listDestory(list* lst){
	if (lst->head || lst == NULL){
		return;
	}
	listNode* cur = lst->head;
	while (cur){
		listNode* next = cur->next;
		free(cur);
		cur = next;
	}
	lst->head = NULL;
}


void test(){
	list lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);

}


int  main()
{
	test();
	system("pause");
	return 0;
}