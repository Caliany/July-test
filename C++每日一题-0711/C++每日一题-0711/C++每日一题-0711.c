//1.
#include <iostream>
using namespace std;
class MyClass{
public:
	MyClass(int i = 0){ cout << 1 << endl; }
	MyClass(const MyClass&x){ cout << 2<<endl; }
	MyClass &operator=(const MyClass&x){ cout << 3<<endl; return *this; }
	~MyClass(){ cout << 4<<endl; }
};
int main(){
	MyClass obj1(1), obj2(2), obj3(obj1);
	system("pause");

}

/*˼·������ֻ������B��A���ұߣ�ֻ��һ���߷���B��A���±ߣ�Ҳֻ��һ���߷�;
B��A�����½ǵ������Ҳ�������߷����������������
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void fillForm(int a[][100], int x, int y){
	int i, j = 0;
	for (i = 1; i <= x; ++i){
		for (j = 1; j <= y; ++j){
			if (i == 1 && j == 1){
				a[i][j] = 1;//ֻ�Ѓɂ����ĕr�򣬾�һ�N�߷�
			}
			else{
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		}
	}
}
int main(){
	int a[100][100] = { 0 };
	int x, y;
	scanf("%d%d", &x, &y);
	fillForm(a, x, y);
	printf("%d", a[x][y]);
	system("pause");
	return 0;
}