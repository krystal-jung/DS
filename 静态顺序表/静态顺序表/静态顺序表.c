#define N 1024
#include <stdio.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType array[N];  // ��������
	size_t size;          // ��Ч���ݵĸ���
}SeqList;