/*
ÿ���ܽ᣺
1������һ��Ա����ʱ��ʹ�ö�̬���������ǣ�<ͨ��ָ������õ���һ���麯��>
2������Ӧ�����£�sum<int>::foo(1,3);
*****3��ʹ��printf������ӡһ��double���͵����ݡ�Ҫ�����Ϊʮ���ƣ���������30���ַ���4λ���ȡ�
		���ʾΪ:   %-30.4f
4��const����ֻ�ܵ���const���ͳ�Ա������
5�����ڵ�����ʧЧ��������
	a.vector��ɾ������ֻ�ᵼ��ָ��ɾ��Ԫ�ؼ�����ĵ�����ʧЧ
	b.map�Ĳ���������ᵼ�µ�����ʧЧ
	c.map��ɾ������ֻ�ᵼ��ָ��ɾ��Ԫ�صĵ�����ʧЧ
*/

//1.

#include<stdio.h>
#include <stdlib.h>
int main(){
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);
	system("pause");//��������a=1,b=0,c=2
	return 0;
}


//2.
#include <iostream>
using namespace std;

class A{
public:
	A(){ p(); }
	virtual void p(){ printf("A"); }
	virtual ~A(){ p(); }
};
class B :public A{
public:
	B(){ p(); }
	void p(){ printf("B"); }//�����ABBA
	~B(){ p(); }
};
int main(int, char**){
	A* a = new B();
	delete a;
	system("pause");
}


//3.

#include <iostream>
using namespace std;

class A
{
public:
	~A(){
		cout << "A()";
	}
};
class B
{
public:
	virtual ~B(){
		cout << "~B()";
	}
};

class C :public A, public B{
public:
	~C(){
		cout << "~C()";
	}
};
int main(){
	C * c = new C;
	B * b1 = dynamic_cast<B *>(c);
	A * a2 = dynamic_cast<A *>(b1);
	delete a2;
}


//�������
#include <stdio.h>
#include<stdlib.h>

#define N 10

int main()
{
	int arr[N][N] = { 0 };
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int m = 0;
		for (m = 0; m < N - i; m++)
		{
			printf("  ");
		}
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			if ((0 == j) || (i == j))
			{
				arr[i][j] = 1;

			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];

			}
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


//������ǵı���
#include<iostream>
using namespace std;

//�õݹ��˼����
int san(int i, int j){
	if (j == 1 || j == i * 2 - 1)
		return 1;
	if (j<1 || j>i * 2 - 1)
		return 0;
	else
		return san(i - 1, j - 2) + san(i - 1, j - 1) + san(i - 1, j);
}
int main(){
	int n;
	cin >> n;
	for (int j = 1; j <= 2 * n - 1; j++){
		if (san(n, j) % 2 == 0){
			cout << j << endl;//��ż���Ļ�����������ż��
			break;
		}
		else if (j == 2 * n - 1)
			cout << "-1" << endl;
	}
	system("pause");
}


#include <iostream>
using namespace std;

class A{
public:
	void print(){
		cout << "A:print()";
	}
};
class B :private A{
public:
	void print(){
		cout << "B:print()";
	}
};
class C : public B{
public:
	void print(){
	//A:: print();//���ɷ��ʣ���Ϊ"B"ʹ��"private"��"A"�̳�
	}
};
int main(){
	C b;
	b.print();
}