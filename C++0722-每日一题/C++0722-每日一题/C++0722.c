//1.题目描述：活动期间每3个空瓶子可以换取一瓶水，现有10瓶水，(在问老板要一个空瓶紫的情况下)可以换取5瓶水。
#include <iostream>
using namespace std;
int Drink(int start){
	int sum = 0;
	while (start > 1){
		sum = sum + start / 3;//3瓶可以换一个空瓶
		start = start / 3 + start % 3;//空瓶的个数
		if (start == 2){
			sum += 1;//剩2个空瓶的时候，可以再要一个空瓶凑成3个空瓶又可以换一瓶
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


//2.题目描述：兔子生小兔子问题，从出生后三个月起小兔子每个月都生一只小兔子，假设兔子都不会死，问每个月小兔子的个数。
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


//通过指针变量访问整型变量
#include<stdio.h>
int main(){
	int a = 100 ;
	int b = 10;
	int *p_1, *p_2;//定义指向整型数据的指针变量p_1,p_2
	p_1 = &a;//把变量a的地址赋给指针变量p_1
	p_2 = &b;//同上
	printf("a=%d,b=%d\n", a, b);//输出变量a,b的值
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

//指针变量作为函数参数
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