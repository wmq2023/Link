#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

enum STACK_OP
{
	STACK_ERROR = -1,
	STACK_OK = 0,
	STACK_FULL = 1,
	STACK_EMPTY = 2
};


typedef char data_t;

typedef struct Stack
{
	data_t data[SIZE];
	int iTop;  //栈顶元素的下标，就是你数组中最后那个元素的下标 元素个数=iTop+1
}Stack;

Stack *createStack();
int pushStack(Stack *pStack, data_t data);
int popStack(Stack *pStack, data_t *pData);
void destroyStack(Stack **ppSTack);
int stackCount(Stack *pStack);



#endif
