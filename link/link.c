


#include "link.h"

//创建一个新的节点
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
//创建空链表
//没有一个节点
//pHead = NULL
//count = 0
//返回值：空链表表结构的首地址
Link *createLink()
{
	Link *pLink = (Link *)malloc(sizeof(Link));
	if(NULL == pLink)
	{
		return NULL;
	}
	memset(pLink, 0, sizeof(Link));
	return pLink;
}

//头部插入
//只要插入一个元素pHead就要被更新
int pushItemFront(Link *pLink, data_t data)
{
	if(NULL == pLink)
	{
		return LINK_ERROR;
	}

	//创建一个节点
	Node *pNode = createNode(data);

	//将新的节点插入到链表中
	pNode->pNext = pLink->pHead;
	pLink->pHead = pNode;

	pLink->count++;
	return LINK_OK;
}
int pushItemBack(Link *pLink, data_t data)
{

}

//在指定的位置插入元素
//位置编号从0开始
//要插入节点必须先找到要插入位置的前一个节点
int insertItemLink(Link *pLink, int iOffset, data_t data)
{
	if(NULL == pLink || iOffset < 0 || iOffset > pLink->count)
	{
		return LINK_ERROR;
	}

	//当iOffset为0时，就是头插，需要单独处理 
	if(0 == iOffset)
	{
		pushItemFront(pLink, data);
		return LINK_OK;
	}
	
	//创建一个新的节点
	Node *pNode = createNode(data);
	//找到要插入位置的前一个节点，用pTmp表示
	Node *pTmp = pLink->pHead;
	int i;
	for(i = 0; i < iOffset-1; i++)
	{
		pTmp = pTmp->pNext;
	}
	//插入
	pNode->pNext = pTmp->pNext;
	pTmp->pNext = pNode;

	//元素个数加1
	pLink->count++;
	return LINK_OK;
}
void showLink(Link *pLink)
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

//销毁链表
//一个节点一个节点的销毁
//最后将表结构也销毁
//也就是所有malloc出来的，都得free
void destroyLink(Link **ppLink)
{
	if(NULL == ppLink || NULL == *ppLink)
	{
		return;
	}
	Node *pDel = (*ppLink)->pHead;
	//释放一个一个的节点
	while(pDel != NULL)
	{
		(*ppLink)->pHead = pDel->pNext;
		free(pDel);
		pDel = (*ppLink)->pHead;
	}
	//释放表结构
	free(*ppLink);
	*ppLink = NULL;
}

//删除指定位置的元素
//位置从0开始
int deleteItemLink(Link *pLink, int iOffset, data_t *pData)
{
	if(NULL == pLink || iOffset < 0 || iOffset >= pLink->count)
	{
		return LINK_ERROR;
	}
	
	//pTmp是要删除的节点的前一个节点
	Node *pTmp = pLink->pHead;
	int i;
	for(i = 0; i < iOffset-1; i++)
	{
		pTmp = pTmp->pNext;
	}
	//pDel是要删除的节点
	Node *pDel = pTmp->pNext;
	if(NULL != pData)
	{
		*pData = pDel->data;
	}

	pTmp->pNext = pDel->pNext;
	free(pDel);
	pDel = NULL;
	pLink->count--;
	return LINK_OK;
}

//按照id查找名字
//如果没找到返回NOT_FOUND
int findItemLink(Link *pLink, data_t *pData)
{
	if(NULL == pLink || NULL == pData)
	{
		return LINK_ERROR;
	}
    //遍历链表，根据传进来的id一个一个去比较
	//如果相等了，就将name带出去
	Node *pTmp = pLink->pHead;
	while(pTmp != NULL)
	{
		if(pTmp->data.id == pData->id)
		{
			strcpy(pData->name, pTmp->data.name);
			return LINK_OK;
		}
		pTmp = pTmp->pNext;
	}

	return NOT_FOUND;
}
