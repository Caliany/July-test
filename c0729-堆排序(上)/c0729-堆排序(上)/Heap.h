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

//用数组初始化堆
void HeapInit(Heap* hp, HPDataType* array, int size, PCOM compare);

//初始化一个空堆
void HeapInitEmpty(Heap* hp, int capacity, PCOM compare);

//销毁堆
void HeapDestroy(Heap* hp);
//void HeapPush(Heap* hp, HPDataType* x);
//void HeapPop(Heap* hp);

//获取堆顶元素
HPDataType HeapTop(Heap *hp);

//获取堆中有效元素的个数
int Heapsize(Heap* hp);

//检测堆是否为空堆
int HeapEmpty(Heap* hp);

//在堆中插入值为data的元素
void HeapInsert(Heap* hp, HPDataType data);
void HeapErase(Heap* hp);
//检测容量
void CheckCapacity(Heap* hp);
void TestHeap();

void HeapSort(int* arr, int size);