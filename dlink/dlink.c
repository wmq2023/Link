#include "dlink.h"

DLink *createDLink()
{
	DLink *pLink = (DLink *)malloc(sizeof(DLink));
	if(NULL == pLink)
	{
		return NULL;
	}
	memset(pLink, 0, sizeof(DLink));
	return pLink;
}


//在第一个节点的前面插入你给的元素
int pushItemFront(DLink *pLink, data_t data)
{
	if(NULL == pLink)
	{
		return DLINK_ERROR;
	}
	//创建一个新的节点
	Node *pNode = createNode(data);

	//插入
	if(pLink->count > 0)
	{
		//因为当插入第一个元素的时候pHead = NULL
		pLink->pHead->pPri = pNode;
	}
	pNode->pNext = pLink->pHead;
	pLink->pHead = pNode;

	pLink->count++;
	return DLINK_OK;
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


void showDLink(DLink *pLink)
{
	if(NULL == pLink)
	{
		return;
	}
	Node *pTmp = pLink->pHead;

	while(pTmp != NULL)
	{
		printf("id:%d name:%s\n", pTmp->data.id, pTmp->data.name);
		pTmp = pTmp->pNext;
	}
}


int insertItemDLink(DLink *pLink, int iOffset, data_t data)
{
	if(NULL == pLink || iOffset < 0 || iOffset > pLink->count)
	{
		return DLINK_ERROR;
	}

	//创建一个新的节点
	Node *pNode = createNode(data);


	if(0 == iOffset)
	{
		pushItemFront(pLink, data);
		return DLINK_OK;
	}

	if(pLink->count == iOffset)
	{
		pushItemBack(pLink, data);
		return DLINK_OK;
	}

	//先找到要插入位置的前一个节点
	Node *pTmp = pLink->pHead;
	int i;
	for(i = 0; i < iOffset-1; i++)
	{
		pTmp = pTmp->pNext;
	}

	pNode->pNext = pTmp->pNext;
	pTmp->pNext->pPri = pNode;
	pTmp->pNext = pNode;
	pNode->pPri = pTmp;

	pLink->count++;
	return DLINK_OK;

}

//尾部插入
int pushItemBack(DLink *pLink, data_t data)
{
	if(NULL == pLink)
	{
		return DLINK_ERROR;
	}

	//创建一个新的节点
	Node *pNode = createNode(data);

	if(0 == pLink->count)
	{
		pushItemFront(pLink, data);
		return DLINK_OK;
	}

	Node *pTmp = pLink->pHead;
	int i;
	for(i = 0; i < pLink->count-1; i++)
	{
		pTmp = pTmp->pNext;
	}

	pTmp->pNext = pNode;
	pNode->pPri = pTmp;
	pLink->count++;
	return DLINK_OK;
}




void destroyDLink(DLink **ppLink)
{
	if(NULL == ppLink || NULL == *ppLink)
	{
		return;
	}

	Node *pDel = (*ppLink)->pHead;

	while(pDel != NULL)
	{
		(*ppLink)->pHead = pDel->pNext;
		free(pDel);
		pDel = (*ppLink)->pHead;
	}
	free(*ppLink);
}


//头部删除
int popItemFront(DLink *pLink)
{
	if(NULL == pLink || 0 == pLink->count)
	{
		return DLINK_ERROR;
	}

	//pDel此时是要删除的首节点
	Node *pDel = pLink->pHead;

	pLink->pHead = pDel->pNext;

	//如果只有一个节点，就不需要给pPri赋值了
	if(1 < pLink->count)
	{
		pLink->pHead->pPri = NULL;
	}

	free(pDel);
	pDel = NULL;

	pLink->count--;
	return DLINK_OK;
}
int popItemBack(DLink *pLink)
{
	if(NULL == pLink || 0 == pLink->count)
	{
		return DLINK_ERROR;
	}

	Node *pTmp = pLink->pHead;
	//如果只有一个节点
	if(1 == pLink->count)
	{
		printf("count = 1...\n");
		free(pLink->pHead);
		pLink->pHead = NULL;
		pLink->count--;
		return DLINK_OK;
	}

	int i;
	for(i = 0; i < pLink->count-2; i++)
	{
		pTmp = pTmp->pNext;
	}
	Node *pDel = pTmp->pNext;
	pTmp->pNext = NULL;
	free(pDel);
	pDel = NULL;
	pLink->count--;
	return DLINK_OK;
}

int deleteItemDLink(DLink *pLink, int iOffset)
{
	if(NULL == pLink || iOffset < 0 || iOffset >= pLink->count || 0 == pLink->count)
	{
		return DLINK_ERROR;
	}

	Node *pTmp = pLink->pHead;

	if(1 == pLink->count || 0 == iOffset)
	{
		popItemFront(pLink);
		return DLINK_OK;
	}
	if(iOffset == pLink->count-1)
	{
		popItemBack(pLink);
		return DLINK_OK;
	}
	int i;
	for(i = 0; i < iOffset-1; i++)
	{
		pTmp = pTmp->pNext;
	}
	Node *pDel = pTmp->pNext;
	pTmp->pNext = pDel->pNext;
	pDel->pNext->pPri = pTmp;
	free(pDel);
	pDel = NULL;
	pLink->count--;
	return DLINK_OK;
}

//更新，main输入要更新的id还有新的name
//循环遍历找到id，更新name

int updateItemDLink(DLink *pLink, data_t *pData)
{
	if(NULL == pLink || NULL == pData)
	{
		return DLINK_ERROR;
	}

	Node *pTmp = pLink->pHead;
	while(pTmp != NULL)
	{
		if(pTmp->data.id == pData->id)
		{
			strcpy(pTmp->data.name, pData->name);
			return DLINK_OK;
		}
		pTmp = pTmp->pNext;
	}
	return NOT_FOUND;
}
