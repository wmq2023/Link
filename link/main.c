#include "link.h"

int main()
{
	Link *pLink = createLink();
	if(NULL == pLink)
	{
		return -1;
	}

	data_t data1 = {1, "李四"};
	data_t data2 = {2, "张三"};
	pushItemFront(pLink, data1);
	pushItemFront(pLink, data2);

	showLink(pLink);
	printf("*******************************\n");

	data_t data3 = {3, "王五"};
	insertItemLink(pLink, 0, data3);
	showLink(pLink);
	printf("*******************************\n");
	data_t data4 = {4, "赵六"};
	insertItemLink(pLink, 3, data4);
	showLink(pLink);
	printf("*******************************\n");


	deleteItemLink(pLink, 2, NULL);
	showLink(pLink);


	data_t data = {0};
	printf("id:");
	scanf("%d",&data.id);
	int ret = findItemLink(pLink, &data);
	if(LINK_ERROR == ret)
	{
		printf("findItemLink error!\n");
	}
	else if(NOT_FOUND == ret)
	{
		printf("没有这个id号!\n");
	}
	else 
	{
		printf("id为%d的人是%s\n", data.id, data.name);
	}
	destroyLink(&pLink);
	return 0;
}
