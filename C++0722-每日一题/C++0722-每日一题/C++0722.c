//1.��Ŀ��������ڼ�ÿ3����ƿ�ӿ��Ի�ȡһƿˮ������10ƿˮ��(�����ϰ�Ҫһ����ƿ�ϵ������)���Ի�ȡ5ƿˮ��
#include <iostream>
using namespace std;
int Drink(int start){
	int sum = 0;
	while (start > 1){
		sum = sum + start / 3;//3ƿ���Ի�һ����ƿ
		start = start / 3 + start % 3;//��ƿ�ĸ���
		if (start == 2){
			sum += 1;//ʣ2����ƿ��ʱ�򣬿�����Ҫһ����ƿ�ճ�3����ƿ�ֿ��Ի�һƿ
			break;
		}
	}
	return sum;
}
int main(){
	int num;
	while (cin >> num){
		cout << Drink(num) << endl;
	}
	system("pause");
	return 0;
}


//2.��Ŀ������������С�������⣬�ӳ�������������С����ÿ���¶���һֻС���ӣ��������Ӷ�����������ÿ����С���ӵĸ�����
#include<iostream>
using namespace std;

int main(){
	int m;
	while (cin >> m){
		int Fir = 1;
		int Sec = 1;
		int sum;
		for (int i = 3; i <= m; i++){
			sum = Fir + Sec;
			Fir = Sec;
			Sec = sum;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}


//ͨ��ָ������������ͱ���
#include<stdio.h>
int main(){
	int a = 100 ;
	int b = 10;
	int *p_1, *p_2;//����ָ���������ݵ�ָ�����p_1,p_2
	p_1 = &a;//�ѱ���a�ĵ�ַ����ָ�����p_1
	p_2 = &b;//ͬ��
	printf("a=%d,b=%d\n", a, b);//�������a,b��ֵ
	printf("*p_1=%d,*p_2=%d\n",*p_1, *p_2);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(){
	int *p1, *p2, *p, a, b;
	printf("please input two integer number:\n");
	scanf("%d%d", &a, &b);
	p1 = &a;
	p2 = &b;
	if (a < b){
		p = p1;
		p1 = p2;
		p2 = p;
	}
	printf("a=%d,b=%d\n", a, b);
	printf("max=%d, min=%d\n", *p1, *p2);
	system("pause");
	return 0;
}

//ָ�������Ϊ��������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void swap(int *p1, int *p2){
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
int main(){
	int a,  b;
	int *p_1, *p_2;
	printf("please input two integer number:\n");
	scanf("%d%d", &a, &b);
	p_1 = &a;
	p_2 = &b;
	if (a < b)
		swap(p_1, p_2);
	printf("max=%d,min=%d\n", a, b);
	system("pause");
	return 0;
}