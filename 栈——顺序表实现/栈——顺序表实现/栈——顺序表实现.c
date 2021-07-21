#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int SeqStackType;

typedef struct SeqStack
{
	SeqStackType* data;
	size_t size;    //��ЧԪ�ظ���
	size_t capicity;  //������С
}SeqStack;

//�����������
void checkCapicity(SeqStack* stack){
	if (stack == NULL){
		printf("�Ƿ�����\n");
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

//ջ�ĳ�ʼ��
void SeqStackInit(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("�Ƿ�����\n");
		return;
	}
	stack->size = 0;
	stack->capicity = 1024;   //��������
	stack->data = (SeqStackType*)malloc(stack->capicity*sizeof(SeqStack)); //����ռ�
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
		printf("  �Ƿ�����\n");
		return;
	}
	if (stack->size == 0)
	{
		printf("��ջ\n");
		return;
	}
	--stack->size;
}

SeqStackType StackTop(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("  �Ƿ�����\n");
		return 0;
	}
	if (stack->size == 0)
	{
		printf("��ջ\n");
		return 0;
	}
	return stack->data[stack->size - 1];
}

void SeqStackDestory(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("�Ƿ�����\n");
		return;
	}
	stack->size = 0;
	stack->capicity = 0;
	free(stack->data);
	stack->data = NULL;

}