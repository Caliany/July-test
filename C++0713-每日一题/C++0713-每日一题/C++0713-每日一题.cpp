/*
每日总结：
1.在重载一个运算符成为成员函数时，其参数表中没有任何参数，这说明该运算符是“前缀一元运算符”；
2.代码生成阶段的主要任务是：把中间代码变成依赖具体机器的目标代码；
3.当一个类的某个函数被说明为virtual，则该类的所有派生类中的同原型函数“都是虚函数”；
4.析构函数没有参数；
5.*** 当使用free释放掉一个指针内容后，指针变量的值不为NULL；
6.基类中说明了虚函数后，派生类中其对应的函数可以不必说明为虚函数；
7.在公有派生的情况下，派生类中定义的成员函数只能访问原基类的：公有成员和保护成员；
*/


//1.
#include <iostream>
using namespace std;
void main0(){
	int x = 3, y = 3;
	switch (x % 2){
	case 1:
		switch (y){
		case 0:cout << "first";
		case 1:cout << "second";
			break;
		default:cout << "hello";
		}
	case 2:cout << "third" << endl;
	}
	system("pause");//输出"hellothird"
}

//2.
#include <iostream>
using namespace std;

class A{
public:
	virtual void func(int val = 1){
		std::cout << "A->" << val << std::endl;
	}
	virtual void test(){
		func();
	}
};
class B :public A{
public:
	void func(int val = 0){
		std::cout << "B->" << val << std::endl; 
	}
};
int main1(){
	B*p = new B;
	p->test();//输出：B->1
	system("pause");
	return 0;
}

//3.
#include <iostream>
using namespace std;
void main2(){
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
	system("pause");//输出：10,20,30

}