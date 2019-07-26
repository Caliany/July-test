//希尔排序:(直接插入排序的优化)
//基本思想：采用跳跃式间隔分组将数组分组，每个小组内进行排序
//	缺点：不稳定
#if 0
#include<stdio.h>
#include<stdlib.h>

void ShellSort(int arr[]){
	int temp;//定义的临时变量
	int i;
	int j;
	for (int step = lenth / 2; step > 0; step /= 2){
		for (i = step; i < lenth; i++){
			temp = arr[i];//保存每次遍历的元素，为之后的插入排序做准备
			for (j - i - step; (j >= 0 && arr[j]>temp); j -= temp)//遍历结束条件就是下标<0或者不满足规则（升序还是降序）
			{
				arr[j + step] = arr[];
			}
			arr[j + step] = temp;//最后将这个临时变量放到对应的位置
		}
	}
}
int main(){

	return 0;
}
#endif

