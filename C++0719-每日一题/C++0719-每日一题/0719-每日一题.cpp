//1、每日一题
#include <iostream>
using namespace std;

int main0(void){
	const int a = 10;
	int *p = (int *)(&a);
	*p = 20;
	cout << "a="<< a <<", *p = "<<*p<<endl;//输出：a=10,*p=20
	system("pause");
	return 0;
}


//2、
class Base{
public:
	virtual int foo(int x){
		return x * 10;
	}
	int foo(char x[14]){
		return sizeof(x)+10;
	}
};
class Derived :public Base{
	int foo(int x){
		return x * 20;
	}
	virtual int foo(char x[10]){
		return sizeof(x)+20;
	}
};
int mai/1(){
	Derived stDerived;
	Base *pstBase = &stDerived;
	char x[10];
	printf("%d\n", pstBase->foo(100) + pstBase->foo(x));//输出：2014
	system("pause");
	return 0;
}

class A{
public:
	void FuncA(){
		printf("FuncA called\n");
	}
	virtual void FuncB(){
		printf("FuncB called\n");
	}
};
class B :public A{
public:
	void FuncA(){
		A::FuncA();
		printf("FuncAB called\n");
	}
	virtual void FuncB(){
		printf("FuncBB called\n");
	}
};
void  main(void){
	B b;
	A *pa;
	pa = &b;
	A *pa2 = new A;
	pa->FuncA(); 
	pa->FuncB(); 
	pa2->FuncA(); 
	pa2->FuncB();
	delete pa2;
	system("pause");

//输出：FuncA called
	//FuncCBB called
	//FuncA called
	//FuncB called
}

//3、
//结果正确，但会溢出
void swap_int(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

/*4、关于STL的描述：
STL 容器是线程不安全的
当容量不够时，vector内部内存扩展方式是翻倍
std::sort 不是稳定排序
std::bitset 不是一个STL容器
std::stack 默认是用deque实现的
std::string 中可以存储多个'\0'字符
*/