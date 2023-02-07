#ifndef _LINK_H_
#define _LINK_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


enum LINK_OP
{
	LINK_ERROR = -1,
	LINK_OK = 0,
	NOT_FOUND = 1
};

//数据元素类型的定义
typedef struct UsrInfo
{
	int id;  //编号
	char name[20];  //名字
}data_t;

//定义描述单链表中节点的结构体
typedef struct Node
{
	data_t data; //当前节点的数据元素
	struct Node *pNext;//下一个节点的首地址
}Node;

//定义描述单链表的结构体
typedef struct Link
{
	Node *pHead;  //单链表的第一个节点的首地址
	int count; //节点的个数
}Link;


Link *createLink();
int pushItemFront(Link *pLink, data_t data);
int pushItemBack(Link *pLink, data_t data);
int insertItemLink(Link *pLink, int iOffset, data_t data);
int deleteItemLink(Link *pLink, int iOffset, data_t *pData);
int findItemLink(Link *pLink, data_t *pData);
void showLink(Link *pLink);
Node *createNode(data_t data);
void destroyLink(Link **ppLink);

#endif
