
/*
�ġ�
ǰ��ͬʱѡ������
��ѡ�������ļ��Ż��������Ͽ���ʹ������죬һǰһ��Ľ���ѡ��Ԫ�أ�ѡ���������Ԫ�غ�endλ��Ԫ�ؽ�����ѡ��������СԪ�غ�beginλ��Ԫ�ؽ�����
1������ҳ������Ԫ�ص��±��Ѿ���endλ�þͲ��ý�����
2������ҳ�����СԪ�ص��±��Ѿ���begin��λ�þͲ��ý����ˣ�
3��СԪ������պ���endλ�ã�MaxPos��end������֮��MinPos��λ�ñ䵽MaxPosλ�ã�
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
			//СԪ������պ���endλ�ã�MaxPos��end������֮��MinPos��λ�ñ䵽MaxPosλ�ã� 
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
�塢������
*/
void HeapAdjust(int* array, int size, int parent){
	int child = parent * 2 + 1;

	while (child<size){
		//�����Һ����нϴ�ĺ���
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
	//1.����----��� or С��
	//�ҵ�����һ����Ҷ�ڵ�
	int lastleaf = ((size - 2) >> 1);
	//�����0Ҳ��Ҫ������
	while (lastleaf >= 0){
		HeapAdjust(array, size, lastleaf);
		lastleaf--;
	}
	//����ɾ����ʽ
	int end = size - 1;

	while (end){
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

/*
����ð������
���ظ��ķ���Ҫ��������У�һ�αȽ�����Ԫ�أ��������˳�����Ͱ����ǽ�������
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
�ߣ�
���������׼ֵ�ָ�����ַ���
����һ�� 1���趨һ����׼ֵ��Ϊ�˷����������Ϊ���һ��Ԫ�� **
2����������ָ��(Ԫ���±�)�ķ�ʽ����ǰ�����ұȻ�׼ֵ���Ԫ�أ��Ӻ���ǰ�ұȻ�׼ֵС��Ԫ�أ�<��ǰ����һ�Σ��Ӻ���ǰһ��>
3���ҵ�֮������λ�õ�Ԫ�ػ�����
4�����������һ��ʼ�ҵĻ�׼ֵ���������������Ļ�����С�ģ�����begin��end�����ʱ������
5����׼ֵ�������begin��end��ȣ���׼ֵ��С�������end��begin��ȣ�
6�������û�׼ֵʱ������right-1λ�õ�Ԫ�ؽ�����������K��������K������right- 1λ�õ�Ԫ�ز���
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
	//�źû�׼ֵ�����end�Ƚϣ���Ϊend��Ҫ����
	if (begin != right - 1){
		Swap(&array[begin], &array[right - 1]);
	}
	return begin;
}

/*
��������1����һ���ƣ�һ����ǰ�����ұȻ�׼ֵ���Ԫ�أ�һ���Ӻ���ǰ�ұȻ�׼ֵС��Ԫ��
2��begin<end��ʾ����Ԫ�أ�����������������˵��Ԫ��û�ҵ���
3���ҵ��Ȼ�׼ֵ���Ԫ�ؾ���䵽end��λ�ã�Ȼ��end--��
4���ҵıȻ�׼ֵС��Ԫ�أ�����䵽begin��λ�ã�Ȼ��begin++��
5�����ѻ�׼ֵ���뵽begin����end��λ�ã���ʱend��begin��ȣ�
*/
int partion2(int* array, int left, int right){
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;

	while (begin < end){
		//��ǰ�����ұȻ�׼ֵ���Ԫ��
		while (array[begin] < key && begin < end){
			begin++;
		}
		//�������endλ��
		if (begin<end){
			array[end] = array[begin];
			end--;
		}
		//�Ӻ���ǰ�ұȻ�׼ֵС��Ԫ��
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
��������1������ָ�붼��ͷ��ʼ�������û�׼ֵ(���һ��Ԫ��)
2����cur���ڵ�һ��Ԫ�ص�λ�ã�pre����cur��ǰһ��λ��
3��cur��ǵ�Ԫ������Ȼ�׼ֵС��pre��һ��Ȼ���Ƿ���cur��ȣ�
4����ȵ������cur���������ߣ��������ȣ�����cur��preλ�õ�Ԫ�أ�
5����󽫻�׼ֵ�ŵ�pre+1��λ�ã�
*/
int partion3(int* array, int left, int right)
{
	int cur = left;
	int pre = cur - 1;
	int key = array[right - 1];

	while (cur < right)
	{
		//cur��ǵ�Ԫ�رȻ�׼ֵС,����pre��һ������cur��ͬ,˵���м�Ķ��Ȼ�׼ֵ��,����
		//cur��ǵ�Ԫ�رȻ�׼ֵ��,cur������,����pre�ǲ�����,pre�ߺ�cur��ǵıȻ�׼ֵСͬ��
		if (array[cur] < key && ++pre != cur)
		{
			swap(&array[pre], &array[cur]);
		}
		cur++;
	}

	//�������ǻ�׼ֵλ�õ�ֵ,���Ǻ�key�����ֵ����
	if ((pre + 1) != right)
	{
		swap(&array[pre + 1], &array[right - 1]);
	}

	return pre + 1;
}
//����
void QuickSort(int* array, int left, int right){
	//Ԫ�ظ������ٵ�һ��
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
�Կ��ŵ��Ż���
����һ����ֵȡ�з�
1��ȡ��������׼ֵ��ѡ���м����һ��
2��������׼ֵ��Ϊ����ߣ�������Լ��м䣬�м�λ��Ϊleft+(right-left)>>1;
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

//�����ݹ����


/*
�ˣ�
��������Ķ�ѭ��д����1�����Ƚ��ұ߽��ֵѹ��ջ�У��ٽ���߽���ջ������������ϣ�������
2����ȡջ��Ԫ�ص�˳�������left��right�����ջ��Ԫ�ز�Ψһ�����������
3���ٽ��µ������ֵ��ջ
*/
void QucikSortNor(int* array, int size)
{
	int left = 0;
	int right = size;

	Stack s;
	StackInit(&s);

	//ջ��������������,���Է�����ѹ��Ԫ��,��ջ��˳����ǶԵ�
	StackPush(&s, right);
	StackPush(&s, left);

	//ջ������,�Ͷ����Ҳ��ּ����ֱ����
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
�ţ�
�鲢���������ڶ������ĺ������
1���ȶ������еݹ������ٶ��ұߵݹ�����Ȼ���ڹ鲢
2��memcpy������ʱ��ע�����array��tmp��Ҫ����left��
3���鲢�Ĳ���������߷�����ұ߷���ÿ��Ԫ�طֱ�ȴ�С��С���ȷŵ���ʱ�ռ�
4�����Ȳ�һ �ĵ�������ʣ�µ�Ԫ��ֱ�Ӳ嵽����
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

	//���̲�һ�������,��������
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

//�ݹ���
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

//�����װ���������
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
ʮ��
ѭ��д����
1��ѭ��д��������������gap<size,����һ����Ա�ʾ���е����ݣ�
2��right��mid��ȡֵ��Ҫ��������
3���������Ԫ�ؼ���Ϊһ�飬����Ҫ���飻
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