#pragma once
#include <stdio.h>
#include<assert.h>
#include <windows.h>
#include <stdlib.h>

typedef int QueueDataType;

//�����еĵ�����Ľڵ�
typedef struct QueueNode
{
	struct QueueNode* next;
	QueueDataType data;
} QueueNode;

//����
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
} Queue;

void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}
void QueueDestory(Queue* q)
{
	assert(q);
	QueueNode* cur = q->front;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
}
void QueuePush(Queue* q, QueueDataType val)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("�ڴ�����ʧ�ܣ�");
		exit(-1);
	}

	newNode->data = val;
	newNode->next = NULL;

	if (q->front == NULL)
	{
		q->front = q->rear = newNode;
	}
	else
	{
		q->rear->next = newNode;
		q->rear = newNode;
	}

}
void QueuePop(Queue* q)
{

	assert(q);
	assert(q->front);
	QueueNode* next = q->front->next;
	free(q->front);
	q->front = next;
	if (q->front == NULL)
	{
		q->rear = NULL;
	}
}
QueueDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}
QueueDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;
}

//1�ǿն��У�0����
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL ? 1 : 0;
}
int QueueSize(Queue* q)
{
	assert(q);
	int size = 0;
	QueueNode* cur = q->front;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}