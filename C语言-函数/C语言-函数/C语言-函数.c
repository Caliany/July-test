//1.
#include <stdio.h>

//get_max函数的设计
int get_max(int x,int y)
{
	return (x > y) ? (x) : (y);
}
int main0(){
	int num1 = 6;
	int num2 = 12;
	int max = get_max(num1, num2);
	printf("max=%d\n", max);
	system("pause");
	return 0;
}

//2.
#include <stdio.h>
#include <stdlib.h>

void Swap1(int x, int y){
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}
void Swap2(int *px, int *py){
	int temp = 0;
	temp = *px;
	*px = *py;
	*py = temp;
}
int main(){
	int num1 = 1;
	int num2 = 2;
	Swap1(num1, num2);
	printf("Swap1::num1 = %d num2 = %d\n", num1, num2);
	Swap2(&num1, &num2);
	printf("Swap2::num1 = %d num2 = %d\n", num1, num2);
	system("pause");
	return 0;
}