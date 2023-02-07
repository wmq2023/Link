#include "stack.h"



Stack *createStack()
{
	Stack *pStack = (Stack *)malloc(sizeof(Stack));
	if(NULL == pStack)
	{
		return NULL;
	}
	memset(pStack, 0, sizeof(Stack));
	return pStack;
}


Node *createNode(data_t data)
{
	Node *pNode = (Node *)malloc(sizeof(Node));
	if(NULL == pNode)
	{
		return NULL;
	}
	memset(pNode, 0, sizeof(Node));
	pNode->data = data;
	return pNode;
}


int pushStack(Stack *pStack, data_t data)
{
	if(NULL == pStack)
	{
		return STACK_ERROR;
	}

	Node *pNode = createNode(data);

	//入栈
	//头插
	pNode->pNext = pStack->pHead;
	pStack->pHead = pNode;

	pStack->count++;
	return STACK_OK;
}


int popStack(Stack *pStack, data_t *pdata)
{
	if(NULL == pStack || NULL == pdata)
	{
		return STACK_ERROR;
	}

	if(0 == pStack->count)
	{
		return STACK_EMPTY;
	}
	Node *pDel = pStack->pHead;
	pStack->pHead = pDel->pNext;

	*pdata = pDel->data;
	free(pDel);
	pDel = NULL;
	pStack->count--;
	return STACK_OK;
}


void destroyStack(Stack **ppStack)
{

}
