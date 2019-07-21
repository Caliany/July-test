/*
每日总结：
1、调用一成员函数时，使用动态联翩的情况是：<通过指针或引用调用一个虚函数>
2、调用应该如下：sum<int>::foo(1,3);
*****3、使用printf函数打印一个double类型的数据。要求：输出为十进制，输出左对齐30个字符，4位精度。
		则表示为:   %-30.4f
4、const对象只能调用const类型成员函数；
5、对于迭代器失效的描述：
	a.vector的删除操作只会导致指向被删除元素及后面的迭代器失效
	b.map的插入操作不会导致迭代器失效
	c.map的删除操作只会导致指向被删除元素的迭代器失效
*/

//1.

#include<stdio.h>
#include <stdlib.h>
int main(){
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);
	system("pause");//输出结果：a=1,b=0,c=2
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
	void p(){ printf("B"); }//输出：ABBA
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


//杨辉三角
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


//杨辉三角的变形
#include<iostream>
using namespace std;

//用递归的思想解答
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
			cout << j << endl;//是偶数的话，就输出这个偶数
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
	//A:: print();//不可访问，因为"B"使用"private"从"A"继承
	}
};
int main(){
	C b;
	b.print();
}