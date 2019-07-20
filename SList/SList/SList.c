#include "SList.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>


//初始化操作
void SListInit(SList* s)
{
	assert(s);
	s->_pHead = NULL;
}
//创建新的节点
PNode BuySListNode(SDataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));//给新节点申请空间
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;//把相应的数据存到节点内
	return pNewNode;
}
//尾插
void SListPushBack(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (NULL == s->_pHead)
	{
		// 空链表
		s->_pHead = pNewNode;
	}
	else
	{
		// 链表非空
		// 找链表中最后一个节点
		PNode pCur = s->_pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;


		pCur->_pNext = pNewNode;
	}
}
//头删
void SListPopBack(SList* s)
{
	assert(s);
	if (NULL == s->_pHead)  // 空链表
		return;
	else if (NULL == s->_pHead->_pNext) // 只有一个节点
	{
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else
	{
		// 多个节点
		PNode pPre = NULL;
		PNode pCur = s->_pHead;
		while (pCur->_pNext)
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}

		free(pCur);
		pPre->_pNext = NULL;
	}
}

void PrintSList(SList* s)
{
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_pNext;
	}

	printf("NULL\n");
}

void SListPushFront(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
}

void SListPopFront(SList* s)
{
	PNode pDelNode = NULL;
	assert(s);
	if (NULL == s->_pHead)
		return;

	// 找到待删除的节点
	pDelNode = s->_pHead;
	s->_pHead = pDelNode->_pNext;
	free(pDelNode);
}

void SListInsert(PNode pos, SDataType data)
{
	PNode pNewNode = NULL;
	if (NULL == pos)
		return;

	pNewNode = BuySListNode(data);

	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

void SListErase(SList* s, PNode pos)
{
	assert(s);
	if (NULL == pos || NULL == s->_pHead)
		return;

	if (pos == s->_pHead)
	{
		s->_pHead = pos->_pNext;
	}
	else
	{
		PNode pPrePos = s->_pHead;
		while (pPrePos && pPrePos->_pNext != pos)
			pPrePos = pPrePos->_pNext;

		if (pPrePos)
			pPrePos->_pNext = pos->_pNext;
	}

	free(pos);
}

PNode SListFind(SList* s, SDataType data)
{
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur)
	{
		if (pCur->_data == data)
			return pCur;

		pCur = pCur->_pNext;
	}

	return NULL;
}
int SListSize(SList* s)
{
	assert(s);
	PNode pCur = s->_pHead;
	size_t count = 0;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

int SListEmpty(SList* s)
{
	assert(s);
	return NULL == s->_pHead;
}

// 移除链表中第一个值为data的元素
void SListRemove(SList* s, SDataType data)
{
	assert(s);
	if (NULL == s->_pHead)
		return;

	// 1. 找带该节点的位置
	PNode pPre = NULL;
	PNode pCur = s->_pHead;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			if (pCur == s->_pHead)
			{
				s->_pHead = pCur->_pNext;
			}
			else
			{
				pPre->_pNext = pCur->_pNext;
			}

			free(pCur);
			return;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}

	}
}


void TestSList1()
{
	SList s; // _pHead
	SList* p = NULL;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);

	SListInsert(SListFind(&s, 2), 6);

	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	PrintSList(&s);
}

void TestSList2()
{
	SList s;
	SListInit(&s);
	SListPushFront(&s, 1);
	SListPushFront(&s, 2);
	SListPushFront(&s, 3);
	SListPushFront(&s, 4);
	SListPushFront(&s, 5);
	PrintSList(&s);

	SListPopFront(&s);
	PrintSList(&s);

	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	PrintSList(&s);
}


// 不带头结点的单链表
void PushBack(PNode* pHead, SDataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	pNewNode->_pNext = NULL;

	if (NULL == *pHead)
		*pHead = pNewNode;
	else
	{
		// 找链表中的最后一个节点
		PNode pCur = *pHead;
		while (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}

		pCur->_pNext = pNewNode;
	}
}

void TestSList3()
{
	// 不带头节点的单链表
	PNode pHead = NULL;
	PushBack(&pHead, 1);
	PushBack(&pHead, 2);
	PushBack(&pHead, 3);
}

void TestSList()
{
	//TestSList1();
	//TestSList2();
	TestSList3();
}