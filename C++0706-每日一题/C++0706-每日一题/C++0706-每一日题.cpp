
//1.ÿ��һ��
#include <iostream>
using namespace std;
char fun(char x, char y){
	if (x < y)
		return x;
	return y;
}
int main(){
	int a = '1', b = '1', c = '2';
	cout << fun(fun(a, b), fun(b, c));//���1
	system("pause");
	return 0;
}


/*
2.��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
���������� ÿ�������������1������������ I like beijing. 
�����������Ȳ�����100 
��������� �����������֮����ַ���,�Կո�ָ� 
ʾ��1: ����I like beijing. 
���beijing. like I

����Ŀ��������
��������ܼ򵥣����ǽ�һ���ַ����е�ǰ�󵥴ʽ������Ե���Ϊ��λ����
*/
//������˼·1�����Ƚ������ַ������ù������ٱ����ַ������ҳ�ÿ�����ʣ��Ե������á�
//��������ʹ����stl�㷨�е�reverse����������ʹ�õ���������string
#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 
int main() { 
	string s; // ע������Ҫʹ��getline��cin>>s�����ո�ͽ��ս����� 
	getline(cin, s); // ��ת�������� 
	reverse(s.begin(), s.end()); // ��ת���� 
	auto start = s.begin(); 
	while (start != s.end()) { 
		auto end = start; 
		while (end != s.end() && *end != ' ') end++; 
		reverse(start, end); 
		if (end != s.end()) start = end + 1; 
		else
			start = end; 
	}
	cout << s << endl; 
	system("pause");
	return 0; 
}
