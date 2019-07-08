//1.选择题
#include <stdio.h>

int main(){
	int a = 1, b = 2, c = 3, d = 0;
	if (a == 1 && b++ == 2)
	if (b != 2 || c-- != 3)
		printf("%d,%d,%d\n", a, b, c);//输出：1,3,3
	else
		printf("%d,%d,%d\n", a, b, c);
	else
		printf("%d,%d,%d\n", a, b, c);

	return 0;
}
//2.
#include <iostream>
using namespace std;
class parent{
	int i;
protected:
	int x;
public:
	parent(){ x = 0, i = 0; }
	void change(){ x++; i++; };
	void display();
};
class son :public parent{
public:
	void modify();

};
void parent::display(){ cout << "x=" << x << endl; }//输出：x=0 x=2 x=1
void son::modify(){ x++; }
int main(){
	son A; parent B;
	A.display();
	A.change();
	A.modify();
	A.display();
	B.change();
	B.display();
}


/*
Fibonacci数列是这样定义的： 
F[0] = 0 
F[1] = 1 for each i ≥ 2: F[i] = F[i-1] + F[i-2] 
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
给你一 个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，
现在给你一个数N求最少 需要多少步可以变为Fibonacci数。 
输入描述： 输入为一个正整数N(1 ≤ N ≤ 1,000,000), 
输出描述： 输出一个最小的步数变为Fibonacci数"。 
示例1: 输入15  输出2
*/
#include<iostream>
using namespace std;

int main(){
	int F0 = 0, F1 = 1;
	int left = 0, right = 0, N, F;
	cin >> N;
	while (1){
		F = F1 + F0;//基于Fib数列：F[i]=F[i-1]+F[i-2]
		F0 = F1;
		F1 = F;
		//找出比N小且距离N最近的数，求出距离
		if (F < N)
			left = N - F;
		else{
			//找出比Nd大且距离N最近的数，求出距离
			right = F - N;//找到距离为N的最近的左右两个Fib数
			break;
		}
	}
	cout << min(left, right) << endl;//取最小距离
	system("pause");
	return 0;
}