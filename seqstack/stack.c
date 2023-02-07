
#include "stack.h"
Stack *createStack()
{
	Stack *pStack = (Stack *)malloc(sizeof(Stack));
	if(NULL == pStack)
	{
		return NULL;
	}
	memset(pStack, 0, sizeof(Stack));
	pStack->iTop = -1;
	return pStack;
}


int pushStack(Stack *pStack, data_t data)
{
	if(NULL == pStack)
	{
		return STACK_ERROR;
	}
	if(SIZE == pStack->iTop+1)
	{
		return STACK_FULL;
	}

	pStack->iTop++;
	pStack->data[pStack->iTop] = data;
	return STACK_OK;
}

int popStack(Stack *pStack, data_t *pData)
{
	if(NULL == pStack || NULL == pData)
	{
		return STACK_ERROR;
	}
	if(-1 == pStack->iTop)
	{
		return STACK_EMPTY;
	}
	*pData = pStack->data[pStack->iTop];
	pStack->iTop--;
	return STACK_OK;
}
void destroyStack(Stack **ppSTack)
{
	if(NULL == ppSTack || NULL == *ppSTack)
	{
		return;
	}
	free(*ppSTack);
	*ppSTack = NULL;
}
int stackCount(Stack *pStack)
{
	if(NULL == pStack)
	{
		return STACK_ERROR;
	}
	return pStack->iTop+1;
}
