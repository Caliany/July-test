//1.ʵ��һ��ͨ�õļӷ�����

/* 
----��������
ȱ�ݣ������ʸߣ�Ч�ʵͣ������ά���Եͣ��ظ��Եģ��׳���
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
2.ģ��
��������ɻ�
���ͱ�̣���д�������޹ص�ͨ�ô��룬�Ǵ��븴�õ�һ���ֶΡ�ģ���Ƿ��ͱ�̵Ļ�����
ģ���Ϊ������ģ�� / ��ģ��
����ģ���ʽ:
template<typename T1, typename T2,......,typename Tn>
template<class T1>----typename��class�����ﶼ����
����ֵ���� ������(�����б�){}

*/

//����ģ�岻�������ĺ��������Ǳ��������ɴ����ģ��
template<typename T> //����ģ������б����ﶨ��T��һ������
T Add(T left, T right){
	cout <<typeid(T).name() << endl;//typeid�� ������
	return left + right;
}

/*
3.����ģ��ʵ����
����ģ��ԭ��
��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
ͨ��ʵ�ν�T����Ϊint��ͨ��ʵ�ν�T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
�������޷�ȷ���˴����׸ý�Tȷ��Ϊʲô���ͣ�
*/
int main1(){
	//����ʽʵ������
	//��Add����ģ�����ʵ����
	cout << Add(1, 2) << endl;

	//�ڱ���׶Σ���������Ҫ��ʵ�ε����ͽ������ݣ���ȷ��ģ����������T��ʵ�����ͣ����ɾ������͵Ĵ���
	cout << Add(1.0, 2.1) << endl;

	Add(1,(int)2.0);//ǿ��ת������

	//��ʽʵ�������ں��������<>��ָ��ģ�������ʵ������
	//ֱ�ӽ�T������ʵ����Ϊ�������ͣ�����Ҫ��ʵ�ε����ͽ�������
	//�ڴ���ִ��ʱ�����������ʵ�ν�����ʽת��
	Add<double>(1, 2.0);
	system("pause");
	return 0;
}


//һ����ģ�庯�����Ժ���ͬ��ģ�庯��ͬʱ����
template<class T>
T Add(T left, T right){
	return left + right;
}
int Add(int left, int right){
	return left + right;
}
int main2(){
	Add(1, 2);//���ȵ����û�д��
	Add<int>(1, 2);//����ģ�壬����ʾʵ������
	Add<>(1, 2);	//����ʽʵ�����������ȵ���ģ�����ɺ���
	system("pause");
	return 0;
}

/*2. ���ڷ�ģ�庯����ͬ������ģ�壬���������������ͬ���ڵ���ʱ�����ȵ��÷�ģ�庯��������Ӹ�ģ
�������һ��ʵ�������ģ����Բ���һ�����и���ƥ��ĺ����� ��ô��ѡ��ģ��
*/
template<class T1,class T2>
T1 Add(T1 left, T2 right){
	return left + right;
}
int Add(int left, int right){
	return left + right;
}
int main3(){
	Add(1, 2);//���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
	Add(1, 2.0);//ģ�庯���������ɸ���ƥ��İ汾����ѡ��ģ��
	system("pause");
	return 0;
}
class Complex{
public:
	Complex(double real, double image)
		: _real(real)
		, _image(image)
	{}

	Complex operator+(const Complex& c)const  //��������,�ڶ���const��ʹ����ɶ��Ը���һ�㣬��ǰ������Ҫ�޸�
	{
		//Complex temp(*this);//��ʱ�ģ��õ�ǰ����������
		//temp._real += c._real;
		//temp._image += c._image;
		//return temp;
		return Complex(_real + c._real, _image + c._image);//ֱ�ӷ��ز�����ʵ�����鲿�����������д�����ͬ����
	}
private:
	double _real;
	double _image;
};
template<class T>
T Add(const T& left,const T& right)//ģ��ʹ�����ã������βθı�ʵ��
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
T Add(T left, T right){ //����ģ�岻�������Զ�����ת��
	return left + right;
}
int Add(int left, int right){
	return left + right;
}
int main4(){
	cout << Add(1, 2) << endl;
	cout << Add(1, 2.0) << endl;
	cout << Add<double>(1, 2) << endl;//��ʾʵ����
	cout << Add<>(1, 2) << endl;//���ȵ���ģ�����ɺ���
	system("pause");
	return 0;
}

/*
ģ��ı����Ϊ�����׶Σ�
1.ʵ����ǰ---�ȶ�ģ����м򵥵��﷨���
2.ʵ������---�������ͻ����T��ʵ���������ɴ���
*/

//ע��Seqlist���Ǿ������,�Ǳ��������ݱ�ʵ�������������ɾ������ģ��  Seqlist<T>��������
template<class T>
	class Seqlist{
	public:
		Seqlist(size_t capaticy = 3)
			: _array(new T[capaticy])//���µ������ռ���г�ʼ��
			, _size(0)
			, _capacity(capaticy)
		{}

		//��������&��ֵ���������
		~Seqlist(){
			if (_array){
				delete[] _array;//�ͷſռ�
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

		//�������
		//�����±������
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
STL����C++�еı�׼ģ��⣨standard template library��
1.�Գ������ݽṹ�ķ�װ
2.ͨ���㷨���������޹أ�����ģ�壩+�����ݽṹ�޹�
STL���������
����(���ʣ��������ݽṹ��װ)

�㷨��ͨ���㷨----������
�����ݽ����ص��㷨
��������ת������
�������䣺ջ�Ͷ���
��������(�º���)--������������һ��ʹ�õĶ���
�ռ�������������ռ䣬������ͷŵ�

����--���ࣺ
����ʽ���������������ݽṹ�ķ�װ
*** string<�ַ���>�������ַ�������̬˳���
array:��̬��˳���
***	list����ͷ����˫��ѭ������
***	vector����̬��˳���
forward_list:��ͷ����ѭ��������
*	deque:��̬�Ķ�ά����
��������list��queue��priority_queue<���ȼ�����>

string�������ַ���<ǳ����>
�ṹ����̬��˳���(�ռ�)
string�����ӿڵ�Ӧ�ã�����--����--Ԫ�ط���--�޸�--�������---������

*/

#include <string>

void TestString(){

}
int main(){
	//string֧��ֱ�����
	strng s;
	string s1;
	string s2;
	string s3(10,'@');	
	string s4("hello");
	getline(cin, s1);//��ȡһ��
	cout << s4 << endl;
	//cin >> s2;
	cout << s1 << endl;

	if (s.empty()){
		cout << "empty string" << endl;

	}
	else{
		cout << "not empty string" << endl;
	}
	s.clear();//����ЧԪ�صĸ�����գ�����ɾ��Ԫ��
	system("pause");
	return 0;
}