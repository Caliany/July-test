//1.ѡ����
#include <stdio.h>

int main(){
	int a = 1, b = 2, c = 3, d = 0;
	if (a == 1 && b++ == 2)
	if (b != 2 || c-- != 3)
		printf("%d,%d,%d\n", a, b, c);//�����1,3,3
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
void parent::display(){ cout << "x=" << x << endl; }//�����x=0 x=2 x=1
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
Fibonacci��������������ģ� 
F[0] = 0 
F[1] = 1 for each i �� 2: F[i] = F[i-1] + F[i-2] 
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci����
����һ ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1��
���ڸ���һ����N������ ��Ҫ���ٲ����Ա�ΪFibonacci���� 
���������� ����Ϊһ��������N(1 �� N �� 1,000,000), 
��������� ���һ����С�Ĳ�����ΪFibonacci��"�� 
ʾ��1: ����15  ���2
*/
#include<iostream>
using namespace std;

int main(){
	int F0 = 0, F1 = 1;
	int left = 0, right = 0, N, F;
	cin >> N;
	while (1){
		F = F1 + F0;//����Fib���У�F[i]=F[i-1]+F[i-2]
		F0 = F1;
		F1 = F;
		//�ҳ���NС�Ҿ���N����������������
		if (F < N)
			left = N - F;
		else{
			//�ҳ���Nd���Ҿ���N����������������
			right = F - N;//�ҵ�����ΪN���������������Fib��
			break;
		}
	}
	cout << min(left, right) << endl;//ȡ��С����
	system("pause");
	return 0;
}