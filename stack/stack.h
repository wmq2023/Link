#ifndef _STACK_H_
#define _STACK_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char data_t;

enum STACK_OP
{
	STACK_ERROR = -1,
	STACK_OK = 0,
	STACK_EMPTY = 1
};


typedef struct Node
{
	data_t data;
	struct Node *pNext;
}Node;

typedef struct Stack
{
	Node *pHead;
	int count;
}Stack;


Stack *createStack();
Node *createNode(data_t data);
int pushStack(Stack *pStack, data_t data);
int popStack(Stack *pStack, data_t *pdata);
void destroyStack(Stack **ppStack);


#endif
