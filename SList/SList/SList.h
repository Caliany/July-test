#pragma once

typedef int SDataType;

// 链表的节点
typedef struct SListNode
{
	SDataType _data;
	struct  SListNode* _pNext;
}Node, *PNode;

// Node n; n._data = 10;  (&n)->_data = 200
// Node* p = &n;   p->_data = 100;  (*p)._data = 200;

typedef struct SList
{
	PNode _pHead;   // 指向链表中的第一个节点
}SList, *PSList;


void SListInit(SList* s);
PNode BuySListNode(SDataType data);
void SListPopBack(SList* s);
void SListPushFront(SList* s, SDataType data);
void SListPopFront(SList* s);
void SListInsert(PNode pos, SDataType data);
void SListErase(SList* s, PNode pos);
PNode SListFind(SList* s, SDataType data);
int SListSize(SList* s);
int SListEmpty(SList* s);
void SListRemove(SList* s, SDataType data);
void SListRemoveAll(SList* s, SDataType data);



void TestSList();

