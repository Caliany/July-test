
//1.每日一题
#include <iostream>
using namespace std;
char fun(char x, char y){
	if (x < y)
		return x;
	return y;
}
int main(){
	int a = '1', b = '1', c = '2';
	cout << fun(fun(a, b), fun(b, c));//输出1
	system("pause");
	return 0;
}


/*
2.将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
输入描述： 每个测试输入包含1个测试用例： I like beijing. 
输入用例长度不超过100 
输出描述： 依次输出倒置之后的字符串,以空格分割 
示例1: 输入I like beijing. 
输出beijing. like I

【题目解析】：
本题题意很简单，就是将一段字符串中的前后单词交换，以单词为单位逆置
*/
//【解题思路1】：先将整个字符串逆置过来，再遍历字符串，找出每个单词，对单词逆置。
//这里我们使用了stl算法中的reverse，所以这里使用迭代器遍历string
#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 
int main() { 
	string s; // 注意这里要使用getline，cin>>s遇到空格就接收结束了 
	getline(cin, s); // 翻转整个句子 
	reverse(s.begin(), s.end()); // 翻转单词 
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
