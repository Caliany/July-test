
//1.每日一题【选择题】

#include <stdio.h>
int main(){
	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 }, *p;
	int i;
	i = 8;
	p = a + i;
	printf("%s\n", p - 3);//输出
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(){
	int any = 0;
	printf("请选择：(0还是1？)%d\n");
	scanf("%d", &any);
	if (any == 1){
		printf("去睡觉！\n");
	}
	else{
		printf("出去玩\n");
	}
	system("pause");
	return 0;
}


//7/3 每日一题
#include <stdio.h>
int cnt = 0;
int fib(int n){
	cnt++;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else
		return fib(n - 1) + fib(n - 2);
}
void main(){
	fib(8);
	printf("%d\n", cnt); //输出cnt=67
	system("pause");
	return 0;
}


#include <stdio.h>
int main(){
	int a[5] = { 1, 3, 5, 7, 9 };
	int *p = (int *)(&a + 1);
	printf("%d,%d\n", *(a + 1), *(p - 1));//输出 3，9
	system("pause");
	return 0;
}