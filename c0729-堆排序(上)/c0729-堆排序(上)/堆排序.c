
/*直接插入排序：想打牌一样，将要插入的元素与之前排好序的元素比较
1、找出合适的插入位置，将其他元素向后搬移；
2、将要插入的元素插入；
总结:
1、元素集合越接近有序，直接插入排序算法的是时间效率越高
2、时间复杂度：O(N^2);
3、空间复杂度；O(1),是一种稳定的排序算法
*/
void InserSort(int* array, int size){
	for (int i = 1; i < size; ++i){
		int key = array[i];
		int end = i - 1;
		while (key < array[end] && end >= 0){
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
/*
希尔排序:缩小增量排序，使用的也是插入排序的思想，但是gap>1时都是预排序
适用于大量且无序的数据，使用分组的方法来减少元素个数，对每一组进行排序；
1.将相同间隔的元素放在一组；
2.逐个取元素，比较的时候跳过gap个元素;
3.插入的时候也是插入到这个元素的gap位置后;
4.计算得出的gap取值最好是gap/3+1,跳出条件与直接插入排序的gap>0不同，应该是gap>1
总结：
1、希尔排序是插入排序的优化；
2、gap>1时都是预排序，目的是让数组更接近有序。当gap == 1时，数组已经接近有序了，这样就会很快达到优化的效果；
3、其时间复杂度不好计算，平均时间复杂度：O(N^1.3--N^2）；
4、是不稳定的

*/
void ShellSort(int* array, int size){
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; ++i){
			int key = array[i];
			int end = i - gap;
			while (key < array[end] && end >= 0){
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}
/*
选择排序：每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。
首先找到最大元素的下标，然后与最后一个元素互换，中间跳过元素所以是不稳定的排序
缺陷是进行重复比较
1、已经遍历过多少趟就代表j可以选取的元素少多少个，所以取值小于size；
2、最后把选取出来的元素放的位置的下标也是size-1的基础上减去；
思路：1.在元素集合array[i]--array[n-1]中选择关键码最大的元素；
2.若他不是这组元素中的最后一个元素，则将他与这组元素中的最后一个元素交换
3.在剩余的array[i]--array[n-2](array[i+1]--array[n-1])集合中，重复上述步骤，直到集合剩余1个元素

*/
void Swap(int* pLeft, int* pRight){
	int tmp = *pLeft;
	*pLeft = *pRight;
	*pRight = tmp;
}

void SelectSort(int* array, int size){
	for (int i = 0; i < size - 1; ++i){
		int MaxPos = 0;
		for (int j = 0; j < size - i; ++j){
			if (array[j]>array[MaxPos]){
				MaxPos = j;
			}
		}
		if (MaxPos != size - i - 1){
			Swap(&array[MaxPos], &array[size - i - 1]);
		}
	}
}




