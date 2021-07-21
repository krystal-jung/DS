#define N 1024
#include <stdio.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType array[N];  // 定长数组
	size_t size;          // 有效数据的个数
}SeqList;