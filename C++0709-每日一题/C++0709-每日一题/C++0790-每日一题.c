
//1.ÿ��һ�⡾ѡ���⡿
#include <iostream>
using namespace std;

class A{
public:
	A() :m_iVal(0){ test(); }
	virtual void func(){ std:cout << m_iVal << ' ' << endl; }
	void test(){ func(); }
public:
	int m_iVal;


};
class B :public A{
public:
	B(){ test(); }
	virtual void func(){
		++m_iVal;
	std: cout << m_iVal << ' ' << endl;
	}

};
int main(){
	A*p = new B;
	p->test();//��������0 1 2
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int main(){
	int A, B = 0;
	int min = 0;
	int m = 0;
	printf("����������������\n");
	scanf("%d%d", &A, &B);
	m = A*B;
	while (min = A%B){
		A = B;
		B = min;
	}
	min = m / B;
	printf("��С������=%d\n", min);
	system("pause");
	return 0;
}