#ifndef _DLINK_H_
#define _DLINK_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum DLINK_OP
{
	DLINK_ERROR = -1,
	DLINK_OK = 0,
	NOT_FOUND = 1
};


typedef struct UsrInfo
{
	int id;
	char name[20];
}data_t;


//节点
typedef struct Node
{
	//前一个节点的地址
	struct Node *pPri;
	//数据
	data_t data;
	//后一个节点的地址
	struct Node *pNext;
}Node;

//表结构
typedef struct DLink
{
	//首节点的地址
	Node *pHead;
	//节点个数
	int count;
}DLink;


DLink *createDLink();
int pushItemFront(DLink *pLink, data_t data);
Node *createNode(data_t data);
void showDLink(DLink *pLink);
int insertItemDLink(DLink *pLink, int iOffset, data_t data);
int pushItemBack(DLink *pLink, data_t data);
void destroyDLink(DLink **ppLink);
int popItemFront(DLink *pLink);
int popItemBack(DLink *pLink);
int deleteItemDLink(DLink *pLink, int iOffset);
int updateItemDLink(DLink *pLink, data_t *pData);
#endif
