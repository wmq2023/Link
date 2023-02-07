#include "dlink.h"


int main()
{
	//创建双向链表
	DLink *pLink = createDLink();

	data_t data = {0};
	char cmd;
	int iOffset;

	while(1)
	{
		printf("1  头插 2 中间插  3 尾插 4 show 5 头删\n 6 尾删 7 中间删 8 更新\n");
		cmd = getchar();
		switch(cmd)
		{
		case '1':
			printf("input id:");
			scanf("%d", &data.id);
			printf("input name:");
			scanf("%s", data.name);
			pushItemFront(pLink, data);
			break;
		case '2':
			printf("iOffset:");
			scanf("%d", &iOffset);
			printf("input id:");
			scanf("%d", &data.id);
			printf("input name:");
			scanf("%s", data.name);
			insertItemDLink(pLink, iOffset, data);
			break;
		case '3':
			printf("input id:");
			scanf("%d", &data.id);
			printf("input name:");
			scanf("%s", data.name);
			pushItemBack(pLink, data);
			break;

		case '4':
			showDLink(pLink);
			break;

		case '5':
			popItemFront(pLink);
			break;
		case '6':
			popItemBack(pLink);
			break;
		case '7':
			printf("iOffset:");
			scanf("%d", &iOffset);
			deleteItemDLink(pLink, iOffset);
			break;
		case '8':
		{
			printf("请输入你要更新的name的id号：");
			scanf("%d", &data.id);
			printf("请输入新的名字：");
			scanf("%s", data.name);
			int ret = updateItemDLink(pLink, &data);
			if(NOT_FOUND == ret)
			{
				printf("no this id...\n");
			}
			break;
		}
		default:
			//system("clear");
			break;
		}
		getchar();
	}
	destroyDLink(&pLink);
	return 0;
}
