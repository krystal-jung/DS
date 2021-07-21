#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "heap.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void checkCapcity(heap* hp)
{
	if (hp->capacity == hp->size)
	{
		int newC = hp->capacity == 0 ? 1 : 2 * hp->capacity;
		hp->data = (HDataType*)realloc(hp->data, sizeof(HDataType)*newC);
		hp->capacity = newC;
	}
}

void shiftDown(int* arr, int n, int cur)
{
	int child = 2 * cur + 1;
	while (child < n)
	{
		//比较左右子树，找到较小值
		if (child + 1 < n &&arr[child + 1]<arr[child])
		{	
			++child;
			//child时刻保存较小值的下标
		}
		if (arr[child] < arr[cur])
		{
			Swap(&arr[child], &arr[cur]);
			cur = child;
			child = 2 * cur + 1;
		}
		else
		{
			break;
		}
	}
}

void shiftUp(int* arr, int n, int cur)
{
	int parent = (cur - 1) / 2;
	while (cur > 0)
	{
		if (arr[cur] < arr[parent])
		{
			Swap(&arr[cur], &arr[parent]);
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

void heapInit(heap* hp)
{
	assert(hp);
	hp->data = NULL;
	hp->capacity = hp->size = 0;
}

void heapCreate(heap* hp, int* arr, int n)
{
	assert(hp);
	hp->data = (HDataType*)malloc(sizeof(HDataType)*n);
	memcpy(hp->data, arr, sizeof(HDataType)*n);
	hp->capacity = hp->size = n;
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(hp->data, hp->size, i);
	}
}

void heapDestory(heap* hp)
{
	assert(hp);
	free(hp->data);
	hp->data = NULL;
	hp->capacity = hp->size = 0;
}

void heapPush(heap* hp, HDataType val)
{
	assert(hp);
	checkCapcity(hp);
	hp->data[hp->size++] = val;
	shiftUp(hp->data, hp->size, hp->size - 1);
}

void heapPop(heap* hp)
{
	if (hp->size > 0)
	{
		swap(&hp->data[0], &hp->data[hp->size - 1]);
		hp->size--;
		shiftDown(hp->data, hp->size, 0);
	}
}

HDataType heapTop(heap* hp)
{
	assert(hp);
	return hp->data[0];
}

int heapEmpty(heap* hp)
{
	if (hp == NULL || hp->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void heapSort(heap* hp)
{
	assert(hp);
	for (int i = (hp->size - 2) / 2; i >= 0; i--)
	{
		shiftDown(hp->data, hp->size, i);
	}
	int end = hp->size - 1;
	while (end > 0)
	{
		Swap(&hp->data[0], &hp->data[end]);
		shiftDown(hp->data, end, 0); 
			end--;
	}
}


void HeapPrint(heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}