
//1.day3--�ַ������ҵ�����������ִ�
#include<iostream> 
#include<string> 
using namespace std; 

int main() { 
	string str,res,cur; 
	cin>>str; 
	for(int i=0;i<=str.length();i++) 
	{ 
		// ����+=��cur 
		if(str[i]>='0' && str[i]<='9') { 
			cur+=str[i]; 
		}
		else { 
			// �ҳ��������ַ�����������ַ��� 
			if(res.size() < cur.size()) res=cur; 
			else
				cur.clear(); 
		} 
	}
	cout<<res;
	system("pause");
	return 0; 
}
/*
�������캯���������඼���ڣ��ø�ֵ�ķŷ�
��ֵ��������أ�
��������أ�
*/

int main(){
	Date d1(2019,7,12)��
	Date

}