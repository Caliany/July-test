
//1.day3--字符串中找到连续最长的数字串
#include<iostream> 
#include<string> 
using namespace std; 

int main() { 
	string str,res,cur; 
	cin>>str; 
	for(int i=0;i<=str.length();i++) 
	{ 
		// 数字+=到cur 
		if(str[i]>='0' && str[i]<='9') { 
			cur+=str[i]; 
		}
		else { 
			// 找出更长的字符串，则更新字符串 
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
拷贝构造函数：两个类都存在，用赋值的放法
赋值运算符重载：
运算符重载：
*/

int main(){
	Date d1(2019,7,12)；
	Date

}