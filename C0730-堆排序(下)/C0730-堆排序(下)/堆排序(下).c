
/*
四、
前后同时选择排序：
对选择的排序的简单优化，理论上可以使排序更快，一前一后的进行选择元素，选出来的最大元素和end位置元素交换，选出来的最小元素和begin位置元素交换；
1、如果找出的最大元素的下标已经在end位置就不用交换；
2、如果找出的最小元素的下标已经在begin的位置就不用交换了；
3、小元素如果刚好在end位置，MaxPos和end交换过之后，MinPos的位置变到MaxPos位置；
*/
void SelectSort2(int* array, int size){
	for (int i = 0; i < size - 1; ++i){
		int begin = 0;
		int end = size - 1;

		while (begin < end){
			int MaxPos = begin;
			int MinPos = begin;
			int index = begin + 1;
			while (index <= end){
				if (array[index]>array[MaxPos]){
					MaxPos = index;
				}
				if (array[index] < array[MinPos]){
					MinPos = index;
				}
				index++;
			}
			if (MaxPos != end){
				Swap(&array[MaxPos], &array[end]);
			}
			//小元素如果刚好在end位置，MaxPos和end交换过之后，MinPos的位置变到MaxPos位置； 
			if (MinPos == end){
				MinPos = MaxPos;
			}
			if (MinPos != begin){
				Swap(&array[MinPos], &array[begin]);
			}
			begin++;
			end--;
		}
	}
}

/*
五、堆排序
*/
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

/*
六、冒泡排序
它重复的访问要排序的数列，一次比较两个元素，如果他们顺序错误就把他们交换过来
*/
void BubbleSort(int* array, int size){
	int i = 0;
	int j = 0;
	for (i; i < size; ++i){
		for (j = size - 1; j>i; --j){
			if (array[j - 1] > array[j]){
				Swap(&array[j - 1], &array[j]);
			}
		}
	}
}

/*
七：
快速排序基准值分割的三种方法
方法一： 1、设定一个基准值，为了方便起见，设为最后一个元素 **
2、采用两个指针(元素下标)的方式，从前往后找比基准值大的元素，从后往前找比基准值小的元素；<从前往后一次，从后往前一次>
3、找到之后将两个位置的元素互换；
4、极端情况是一开始找的基准值就是整个数据最大的或者最小的，所以begin与end不相等时交换；
5、基准值最大的情况begin与end相等；基准值最小的情况下end与begin相等；
6、最后放置基准值时必须与right-1位置的元素交换，不能与K交换，与K交换，right- 1位置的元素不变
*/
int Partion1(int* array, int left, int right){
	int key = array[right - 1];
	int begin = left;
	int end = right + 1;

	while (begin<end){
		while (array[begin] <= key && begin < end){
			begin++;
		}
		while (array[begin] >= key && begin < end){
			end--;
		}
		if (begin != end){
			Swap(&array[begin], &array[end]);
		}
	}
	//放好基准值后，需和end比较，因为end是要动的
	if (begin != right - 1){
		Swap(&array[begin], &array[right - 1]);
	}
	return begin;
}

/*
方法二：1、与一类似，一个从前往后找比基准值大的元素，一个从后往前找比基准值小的元素
2、begin<end表示还有元素，如果不满足这个条件说明元素没找到；
3、找到比基准值大的元素就填充到end的位置，然后end--；
4、找的比基准值小的元素，就填充到begin的位置，然后begin++；
5、最后把基准值插入到begin或者end的位置，此时end和begin相等；
*/
int partion2(int* array, int left, int right){
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;

	while (begin < end){
		//从前往后找比基准值大的元素
		while (array[begin] < key && begin < end){
			begin++;
		}
		//填充最后的end位置
		if (begin<end){
			array[end] = array[begin];
			end--;
		}
		//从后往前找比基准值小的元素
		while (array[end] > key && begin < end)
		{
			end--;
		}

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}

	array[begin] = key;
	return begin;
}
/*
方法三：1、两个指针都从头开始，先设置基准值(最后一个元素)
2、将cur放在第一个元素的位置，pre放在cur的前一个位置
3、cur标记的元素如果比基准值小，pre走一步然后看是否与cur相等；
4、相等的情况，cur继续往下走，如果不相等，交换cur和pre位置的元素；
5、最后将基准值放到pre+1的位置；
*/
int partion3(int* array, int left, int right)
{
	int cur = left;
	int pre = cur - 1;
	int key = array[right - 1];

	while (cur < right)
	{
		//cur标记的元素比基准值小,并且pre走一步不和cur相同,说明中间的都比基准值大,交换
		//cur标记的元素比基准值大,cur继续走,但是pre是不动的,pre走和cur标记的比基准值小同步
		if (array[cur] < key && ++pre != cur)
		{
			swap(&array[pre], &array[cur]);
		}
		cur++;
	}

	//交换的是基准值位置的值,不是和key保存的值交换
	if ((pre + 1) != right)
	{
		swap(&array[pre + 1], &array[right - 1]);
	}

	return pre + 1;
}
//快排
void QuickSort(int* array, int left, int right){
	//元素个数最少的一个
	if (right - left > 1){
		int div = partion3(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

int main(){
	int a[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i){
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

/*
对快排的优化：
方法一：三值取中法
1、取出三个基准值，选择中间的那一个
2、三个基准值分为最左边，最左边以及中间，中间位置为left+(right-left)>>1;
*/

//int GetMiddleIndex(int* array, int left, int right)
//{
//	int mid = left + ((right - left) >> 1);
//
//	if (array[left] < array[right - 1])
//	{
//		if (array[mid] < array[left])
//		{
//			return left;
//		}
//		else if (array[mid]>array[right - 1])
//		{
//			return right - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	else
//	{
//		if (array[mid] > array[left])
//		{
//			return left;
//		}
//		else if (array[mid] < array[right - 1])
//		{
//			return right - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//}

//调整递归深度


/*
八：
块数排序的额循环写法：1、首先将右边界的值压入栈中，再将左边界入栈，这样左就在上，右在下
2、获取栈顶元素的顺序就是先left后right，如果栈中元素不唯一，则继续分组
3、再将新的区间的值入栈
*/
void QucikSortNor(int* array, int size)
{
	int left = 0;
	int right = size;

	Stack s;
	StackInit(&s);

	//栈的特性是先入后出,所以反过来压入元素,出栈的顺序就是对的
	StackPush(&s, right);
	StackPush(&s, left);

	//栈若不空,就对左右部分继续分别分组
	while (StackEmpty(&s) != -1)
	{
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = partion3(array, left, right);

			StackPush(&s, right);
			StackPush(&s, div + 1);
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
}

/*
九：
归并排序：类似于二叉树的后序遍历
1、先对左侧进行递归排序，再对右边递归排序，然后在归并
2、memcpy拷贝的时候注意参数array和tmp都要加上left；
3、归并的操作就是左边分组和右边分组每个元素分别比大小，小的先放到临时空间
4、长度不一 的单独处理，剩下的元素直接插到后面
*/
void MergeData(int* array, int left, int mid, int right, int* tmp)
{
	int begin1 = left;
	int end1 = mid;

	int begin2 = mid;
	int end2 = right;

	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] < array[begin2])
		{
			tmp[index] = array[begin1];
			begin1++;
			index++;
		}
		else
		{
			tmp[index] = array[begin2];
			begin2++;
			index++;
		}
	}

	//长短不一样的情况,单独处理
	while (begin1 < end1)
	{
		tmp[index] = array[begin1];
		index++;
		begin1++;
	}
	while (begin2 < end2)
	{
		tmp[index] = array[begin2];
		index++;
		begin2++;
	}
}

//递归框架
void _MergeSort(int* array, int left, int right, int* tmp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);

		_MergeSort(array, left, mid, tmp);
		_MergeSort(array, mid, right, tmp);

		MergeData(array, left, mid, right, tmp);

		memcpy(array + left, tmp + left, sizeof(int)*(right - left));
	}
}

//对其封装，方便调用
void MergeSort(int* array, int size)
{
	int* tmp = (int*)malloc(sizeof(int)*size);

	if (tmp == NULL)
	{
		assert(0);
	}

	_MergeSort(array, 0, size, tmp);

	free(tmp);
	tmp = NULL;
}

/*
十：
循环写法：
1、循环写法的跳出条件是gap<size,就是一组可以表示所有的数据；
2、right和mid的取值需要单独处理；
3、把有序的元素集合为一组，不需要分组；
*/
void MergeSortNor(int* array, int size)
{
	int* tmp = (int*)malloc(sizeof(int)*size);

	if (tmp == NULL)
	{
		assert(0);
	}

	int gap = 1;

	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			if (right >= size)
			{
				right = size;
			}

			if (mid >= size)
			{
				mid = size;
			}

			MergeData(array, left, mid, right, tmp);
		}

		memcpy(array, tmp, sizeof(int)*size);
		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}