/*
ÿ���ܽ᣺
1.������һ���������Ϊ��Ա����ʱ�����������û���κβ�������˵����������ǡ�ǰ׺һԪ���������
2.�������ɽ׶ε���Ҫ�����ǣ����м�������������������Ŀ����룻
3.��һ�����ĳ��������˵��Ϊvirtual�������������������е�ͬԭ�ͺ����������麯������
4.��������û�в�����
5.*** ��ʹ��free�ͷŵ�һ��ָ�����ݺ�ָ�������ֵ��ΪNULL��
6.������˵�����麯���������������Ӧ�ĺ������Բ���˵��Ϊ�麯����
7.�ڹ�������������£��������ж���ĳ�Ա����ֻ�ܷ���ԭ����ģ����г�Ա�ͱ�����Ա��
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
	system("pause");//���"hellothird"
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
	p->test();//�����B->1
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
	system("pause");//�����10,20,30

}