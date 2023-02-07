#include "stack.h"


int main()
{
	Stack *pStack = createStack();
	if(NULL == pStack)
	{
		printf("create stack error!\n");
		return -1;
	}

	char c;
	while(1)
	{
		scanf("%c", &c);
		int ret = pushStack(pStack, c);
		if(STACK_ERROR == ret)
		{
			return -1;
		}
		else if(STACK_FULL == ret)
		{
			break;
		}
	}


	while(1)
	{
		int ret = popStack(pStack, &c);
		if(STACK_ERROR == ret)
		{
			return -1;
		}
		else if(STACK_EMPTY == ret)
		{
			break;
		}
		printf("%c", c);
	}
	printf("\n");
	destroyStack(&pStack);
	return 0;
}
