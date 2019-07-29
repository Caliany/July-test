#include "Heap.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

void Swap(HPDataType* pLeft, HPDataType* pRight){
	HPDataType temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

void AdjustDown(HPDataType* array, int size, int parent, PCOM Compare){
	//默认让child标记parent的左孩子，因为：完全二叉树某个节点如果只有一个孩子，那一定是其双亲的左孩子；
	int child = parent * 2 + 1;
	while (child < size){
		//必须保证右孩子存在
		if (child + 1 < size && Compare(array[child + 1], array[child])){
			child += 1;
		}
		if (Compare(array[child], array[parent])){
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void AdjustUP(HPDataType* array, int size, int child, PCOM Compare){
	int parent = (child - 1) / 2;
	while (child){
		if (Compare(array[child], array[parent])){
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			return;
	}
}

void CheckCapacity(Heap* hp){
	assert(hp);
	if (hp->_size == hp->_capacity){
		int newCapacity = hp->_capacity * 2;
		//申请新空间
		HPDataType* tmp = (HPDataType*)malloc(sizeof(HPDataType)*newCapacity);
		if (tmp == NULL){
			assert(0);
			return;
		}
		//拷贝元素
		for (int i = 0; i < hp->_size; ++i)
			tmp[i] = hp->_array[i];

		//释放旧空间
		free(hp->_array);
		hp->_array = tmp;
		hp->_capacity = newCapacity;
	}
}
//建小堆
int Less(HPDataType left, HPDataType right){
	return left < right;
}
//建大堆
int Greater(HPDataType left, HPDataType right){
	return left>right;
}

void HeapInit(Heap* hp, HPDataType* array, int size, PCOM compare){
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (NULL == hp->_array){
		assert(0);
		return;
	}
	hp->_capacity = size;
	for (int i = 0; i < size; ++i)
		hp->_array[i] = array[i];

	hp->_size = size;
	hp->Compare = compare;

	//将该完全二叉树调整让其满足堆的性质
	//找完全二叉树中倒数第一个非叶子节点
	//int root = ((size - 2) >> 1);
	//for (; root >= 0; --root)
	//AdjustDown(hp->_array, size, root, hp->Compare);

	int lastleaf = ((size - 2) >> 1);
	//这等于0也是要调整的
	while (lastleaf >= 0){
		AdjustDown(hp->_array, size, lastleaf, hp->Compare);
		lastleaf--;
	}
}

void HeapInitEmpty(Heap* hp, int capacity, PCOM compare){
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*capacity);
	if (NULL == hp->_array){
		assert(0);
		return;
	}
	hp->_capacity = capacity;
	hp->_size = 0;
	hp->Compare = compare;
}
void HeapInsert(Heap* hp, HPDataType data){
	CheckCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	AdjustUP(hp->_array, hp->_size, hp->_size - 1, hp->Compare);
}
void HeapErase(Heap* hp){
	assert(hp);
	if (HeapEmpty(hp))
		return;
	//把堆顶元素和最后一个元素互换，然后size--，再向上调整
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size -= 1;
	AdjustDown(hp->_array, hp->_size, 0, hp->Compare);
}
int Heapsize(Heap* hp){
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp){
	assert(hp);
	if (hp->_size = 0)
		return 0;
}
HPDataType HeapTop(Heap *hp){
	assert(hp);
	return hp->_array[0];
}
void HeapDestroy(Heap* hp){
	assert(hp);
	if (hp->_array){
		free(hp->_array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

void TestHeap(){
	Heap hp;
	int array[] = { 27, 13, 23, 14, 19, 20, 11, 21, 13, 28 };
	HeapInit(&hp, array, sizeof(array) / sizeof(array[0]), Greater);

	printf("size=%d\n", Heapsize(&hp));
	printf("堆顶：%d\n", HeapTop(&hp));

	HeapErase(&hp);
	printf("删除堆顶元素成功\n");

	printf("size=%d\n", Heapsize(&hp));
	printf("堆顶：%d\n", HeapTop(&hp));

	HeapInsert(&hp, 18);
	printf("插入堆顶元素成功\n");

	printf("size=%d\n", Heapsize(&hp));
	printf("堆顶：%d\n", HeapTop(&hp));

	HeapInsert(&hp, 10);
	printf("插入堆顶元素成功\n");

	printf("size=%d\n", Heapsize(&hp));
	printf("堆顶：%d\n", HeapTop(&hp));

	HeapErase(&hp);
	printf("删除堆顶元素成功！\n");

	printf("size=%d\n", Heapsize(&hp));
	printf("堆顶：%d\n", HeapTop(&hp));
}
int main(){
	TestHeap();
	system("pause");
	return 0;
}

//堆排序
void HeapAdjust(int* array, int size, int parent){
	int child = parent * 2 + 1;
	while (child<size){
		//找左右孩子中较大的孩子
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;
		if (array[child] > array[parent]){
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void HeapSort(int* array, int size){
	//1.建堆----大堆 or 小堆
	//找倒数第一个非叶节点
	int lastleaf = ((size - 2) >> 1);
	//这等于0也是要调整的
	while (lastleaf >= 0){
		HeapAdjust(array, size, lastleaf);
		lastleaf--;
	}
	//排序：删除方式
	int end = size - 1;
	while (end){
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}