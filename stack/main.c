#include "stack.h"


int main()
{
	Stack *pStack = createStack();
	if(NULL == pStack)
	{
		printf("createStack error!\n");
		return -1;
	}

	char str[100] = {0};
	printf("str:");
	gets(str);

	int i = 0;
	int count = 0;
	while(str[i])
	{
		if('(' == str[i])
		{
			pushStack(pStack, str[i]);
		}
		else if(')' == str[i])
		{
			data_t data;
			popStack(pStack, &data);
			count++;
		}
		i++;
	}
	printf("count = %d\n", count);
	return 0;
}
