//ϣ������:(ֱ�Ӳ���������Ż�)
//����˼�룺������Ծʽ������齫������飬ÿ��С���ڽ�������
//	ȱ�㣺���ȶ�
#if 0
#include<stdio.h>
#include<stdlib.h>

void ShellSort(int arr[]){
	int temp;//�������ʱ����
	int i;
	int j;
	for (int step = lenth / 2; step > 0; step /= 2){
		for (i = step; i < lenth; i++){
			temp = arr[i];//����ÿ�α�����Ԫ�أ�Ϊ֮��Ĳ���������׼��
			for (j - i - step; (j >= 0 && arr[j]>temp); j -= temp)//�����������������±�<0���߲�������������ǽ���
			{
				arr[j + step] = arr[];
			}
			arr[j + step] = temp;//��������ʱ�����ŵ���Ӧ��λ��
		}
	}
}
int main(){

	return 0;
}
#endif

