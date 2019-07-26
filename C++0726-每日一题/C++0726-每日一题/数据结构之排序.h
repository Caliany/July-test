#pragma once

typedef int(*PCOM)();
typedef int HPDataType;
typedef struct Heap{
	HPDataType* _arr;
	int _size;
	int _capacity;
}; Heap;

void HeapInit(Heap* hp, HPDataType* arr, int n);
void HeapDestroy(Heap* hp);//销毁空间并释放
void HeapPush(Heap* hp, HPDataType* x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap *hp);
int Heapsize(Heap* hp);
int HeapEmpty(Heap* hp);


void TestHeap();

void HeapSort(int* arr, int size);