#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int SeqStackType;

typedef struct SeqStack
{
	SeqStackType* data;
	size_t size;    //有效元素个数
	size_t capicity;  //容量大小
}SeqStack;

//检查容量扩容
void checkCapicity(SeqStack* stack){
	if (stack == NULL){
		printf("非法输入\n");
		return;
	}
	if (stack->capicity == stack->size){
		int newCapicity = stack->capicity == 0 ? 1 : 2 * stack->capicity;
		SeqStackType* tmp = (SeqStackType*)malloc(sizeof(SeqStackType)*newCapicity);
		memcpy(tmp, stack->data, sizeof(SeqStackType)*stack->size);
		free(stack->data);
		stack->data = tmp;
		stack->capicity = newCapicity;
	}
}

//栈的初始化
void SeqStackInit(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("非法输入\n");
		return;
	}
	stack->size = 0;
	stack->capicity = 1024;   //设置容量
	stack->data = (SeqStackType*)malloc(stack->capicity*sizeof(SeqStack)); //申请空间
}


void SeqStackPush(SeqStack* stack, SeqStackType val)
{
	checkCapicity(stack);
	stack->data[stack->size] = val;
	++stack->size;
}

void SeqStackPop(SeqStack* stack)
{

	if (stack == NULL)
	{
		printf("  非法输入\n");
		return;
	}
	if (stack->size == 0)
	{
		printf("空栈\n");
		return;
	}
	--stack->size;
}

SeqStackType StackTop(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("  非法输入\n");
		return 0;
	}
	if (stack->size == 0)
	{
		printf("空栈\n");
		return 0;
	}
	return stack->data[stack->size - 1];
}

void SeqStackDestory(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("非法操作\n");
		return;
	}
	stack->size = 0;
	stack->capicity = 0;
	free(stack->data);
	stack->data = NULL;

}