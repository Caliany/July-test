/*1.
������n���ַ��������������ַ������ȶ���ͬ���������ѧϰ���������ַ��������򷽷���
1.�����ַ������ֵ����򷽷���"car"<"carriage"<"cats"<"doggies"<"koala";
2.�����ַ����ĳ�������eg."car"<"cats"<"koala"<"doggies"<"carriage"
������֪���Լ�����Щ�ַ��������Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<string> a;
	a.resize(n);
	for (auto &e : a){
		cin >> e;
	}
	int lexico = 1;
	int lengths = 1;

	//�����i�Ǵ�1��ʼ�ģ�
	for (size_t i = 0; i < a.size(); ++i){
		if (a[i - 1] >= a[i]){
			lexico = 0;
			break;
		}
	}

	//�����i�Ǵ�0��ʼ�ģ�
	for (size_t i = 0; i < a.size(); ++i){
		if (a[i].size() >= a[i + 1].size()){
			lengths = 0;
			break;
		}
	}
	if (lexico == 1 && lengths == 1){
		cout << "both";
	}
	else if (lexico == 1 && lengths == 0){
		cout << "lexicographically";
	}
	else if (lexico == 0 && lengths == 1){
		cout << "lengths";
	}
	else {
		cout << "none";
	}
	system("pause");
	return 0;
}

//2.����������
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	����ע������һ��ֵ���Ǵ���Խ�������ıȽϣ�����ο�����
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	��������
	int i = 0; 
	for (i = 0; i < n; ++i) 
		cin >> a[i]; 
	i = 0; 
	int count = 0; 
	while (i < n) { 
		 �ǵݼ������� 
		if (a[i] < a[i + 1]) { 
			while (i < n && a[i] <= a[i + 1]) 
				i++; count++; i++; 
		}
		else if (a[i] == a[i + 1]) { 
			i++; 
		}
		else // �ǵ��������� 
		{ 
			while (i < n && a[i] >= a[i + 1]) 
				i++; count++; i++;
		}
	}
	cout << count << endl; 
	system("pause");
	return 0;
}