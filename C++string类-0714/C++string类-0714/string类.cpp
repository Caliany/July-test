//1.实现一个通用的加法函数

/* 
----函数重载
缺陷：复用率高，效率低；代码可维护性低；重复性的，易出错
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int Add(int a, int b);
double Add(double a, double b);
char Add(char a, char b){
	return a + b;
}
int main0(){
	Add(1, 2);
	Add(1.0, 2.0);
	Add('1', '2');
	return 0;
}


/*
2.模板
举例：造飞机
泛型编程：编写与类型无关的通用代码，是代码复用的一种手段。模板是泛型编程的基础。
模板分为：函数模板 / 类模板
函数模板格式:
template<typename T1, typename T2,......,typename Tn>
template<class T1>----typename和class在这里都可以
返回值类型 函数名(参数列表){}

*/

//函数模板不是真正的函数，它是编译器生成代码的模具
template<typename T> //函数模板参数列表，这里定义T是一个类型
T Add(T left, T right){
	cout <<typeid(T).name() << endl;//typeid： 看类型
	return left + right;
}

/*
3.函数模板实例化
函数模板原理：
因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
通过实参将T推演为int，通过实参将T推演为double类型，但模板参数列表中只有一个T，
编译器无法确定此处到底该将T确定为什么类型？
*/
int main1(){
	//【隐式实例化】
	//对Add函数模板进行实例化
	cout << Add(1, 2) << endl;

	//在编译阶段，编译器需要对实参的类型进行推演，来确认模板参数类表中T的实际类型，生成具体类型的代码
	cout << Add(1.0, 2.1) << endl;

	Add(1,(int)2.0);//强制转换类型

	//显式实例化：在函数名后的<>中指定模板参数的实际类型
	//直接将T的类型实例化为参数类型，不需要对实参的类型进行推演
	//在代码执行时，编译器会对实参进行隐式转换
	Add<double>(1, 2.0);
	system("pause");
	return 0;
}


//一个非模板函数可以和其同名模板函数同时存在
template<class T>
T Add(T left, T right){
	return left + right;
}
int Add(int left, int right){
	return left + right;
}
int main2(){
	Add(1, 2);//优先调用用户写的
	Add<int>(1, 2);//调用模板，【显示实例化】
	Add<>(1, 2);	//【隐式实例化】，优先调用模板生成函数
	system("pause");
	return 0;
}

/*2. 对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而不会从该模
板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模板
*/
template<class T1,class T2>
T1 Add(T1 left, T2 right){
	return left + right;
}
int Add(int left, int right){
	return left + right;
}
int main3(){
	Add(1, 2);//与非模板类型完全匹配，不需要函数模板实例化
	Add(1, 2.0);//模板函数可以生成更加匹配的版本，则选择模板
	system("pause");
	return 0;
}
class Complex{
public:
	Complex(double real, double image)
		: _real(real)
		, _image(image)
	{}

	Complex operator+(const Complex& c)const  //函数重载,第二个const可使代码可读性更高一点，当前对象不需要修改
	{
		//Complex temp(*this);//临时的，用当前对象来构造
		//temp._real += c._real;
		//temp._image += c._image;
		//return temp;
		return Complex(_real + c._real, _image + c._image);//直接返回参数的实部和虚部，与上面四行代码相同作用
	}
private:
	double _real;
	double _image;
};
template<class T>
T Add(const T& left,const T& right)//模板使用引用，不想形参改变实参
{
	return left + right;
}
int main(){
	Add(1, 2);
	Complex c1(1.0, 2.0);
	Complex c2(1.0, 2.0);
	Add(c1, c2);
	system("pause");
	return 0;
}



template<class T>
T Add(T left, T right){ //函数模板不允许函数自动类型转换
	return left + right;
}
int Add(int left, int right){
	return left + right;
}
int main4(){
	cout << Add(1, 2) << endl;
	cout << Add(1, 2.0) << endl;
	cout << Add<double>(1, 2) << endl;//显示实例化
	cout << Add<>(1, 2) << endl;//优先调用模板生成函数
	system("pause");
	return 0;
}

/*
模板的编译分为两个阶段：
1.实例化前---先对模板进行简单的语法检测
2.实例化后---编译器就会根据T的实际类型生成代码
*/

//注意Seqlist不是具体的类,是编译器根据被实例化的类型生成具体类的模具  Seqlist<T>：：才是
template<class T>
	class Seqlist{
	public:
		Seqlist(size_t capaticy = 3)
			: _array(new T[capaticy])//对新的连续空间进行初始化
			, _size(0)
			, _capacity(capaticy)
		{}

		//拷贝构造&赋值运算符重载
		~Seqlist(){
			if (_array){
				delete[] _array;//释放空间
			}
		}

		void PushBack(const T& data){
			_array[_size++] = data;
		}
		void PopBack(){
			if (!= empty())
				return;
			--_size;
		}

		//随机访问
		//重载下标运算符
		T& operator[](size_t index){
			return _array[index];
		}
		size_t Size()const{
			return _size;
		}
		size_t Capacity()const{
			return _capacity;

		}
		bool empty()const{
			return 0 == _size;
		}
	private:
		T* _array;
		size_t _size;
		size_t _capacity;

	};

int main0(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << array[1] << endl;

	Seqlist<int>s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1[4] = 10;
	cout << array[4] << endl;

	Seqlist<double>s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	cout << s2.Size() << endl;
	cout << s2.Capacity() << endl;

	system("pause");
	return 0;
}

/*
STL：是C++中的标准模板库（standard template library）
1.对常见数据结构的封装
2.通用算法：与类型无关（函数模板）+与数据结构无关
STL六大组件：
容器(本质：常见数据结构封装)

算法：通用算法----迭代器
与数据结果相关的算法
适配器：转换作用
容器适配：栈和队列
函数对象(仿函数)--可以像函数调用一样使用的对象
空间配置器：管理空间，申请和释放的

容器--分类：
序列式容器：对线性数据结构的封装
*** string<字符串>：管理字符串，动态顺序表
array:静态的顺序表
***	list：带头结点的双向循环链表
***	vector：动态的顺序表
forward_list:带头结点的循环单链表
*	deque:动态的二维数组
适配器：list、queue、priority_queue<优先级队列>

string：管理字符串<浅拷贝>
结构：动态的顺序表(空间)
string常见接口的应用：构造--容量--元素访问--修改--特殊操作---迭代器

*/

#include <string>

void TestString(){

}
int main(){
	//string支持直接输出
	strng s;
	string s1;
	string s2;
	string s3(10,'@');	
	string s4("hello");
	getline(cin, s1);//获取一行
	cout << s4 << endl;
	//cin >> s2;
	cout << s1 << endl;

	if (s.empty()){
		cout << "empty string" << endl;

	}
	else{
		cout << "not empty string" << endl;
	}
	s.clear();//把有效元素的个数清空，不会删除元素
	system("pause");
	return 0;
}