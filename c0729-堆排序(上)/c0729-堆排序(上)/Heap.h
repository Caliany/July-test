#pragma once

typedef int HPDataType;


int Less(HPDataType left, HPDataType right);
int Greater(HPDataType left, HPDataType right);

typedef int(*PCOM)(HPDataType, HPDataType);
typedef struct Heap{
	HPDataType* _array;
	int _size;
	int _capacity;
	PCOM Compare;
}Heap;

//�������ʼ����
void HeapInit(Heap* hp, HPDataType* array, int size, PCOM compare);

//��ʼ��һ���ն�
void HeapInitEmpty(Heap* hp, int capacity, PCOM compare);

//���ٶ�
void HeapDestroy(Heap* hp);
//void HeapPush(Heap* hp, HPDataType* x);
//void HeapPop(Heap* hp);

//��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap *hp);

//��ȡ������ЧԪ�صĸ���
int Heapsize(Heap* hp);

//�����Ƿ�Ϊ�ն�
int HeapEmpty(Heap* hp);

//�ڶ��в���ֵΪdata��Ԫ��
void HeapInsert(Heap* hp, HPDataType data);
void HeapErase(Heap* hp);
//�������
void CheckCapacity(Heap* hp);
void TestHeap();

void HeapSort(int* arr, int size);