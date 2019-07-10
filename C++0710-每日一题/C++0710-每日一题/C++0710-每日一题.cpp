/*1.
考拉有n个字符串，任意两个字符串长度都不同。考拉最近学习到有两种字符串的排序方法：
1.根据字符串的字典排序方法。"car"<"carriage"<"cats"<"doggies"<"koala";
2.根据字符串的长度排序。eg."car"<"cats"<"koala"<"doggies"<"carriage"
考拉想知道自己的这些字符串排列是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
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

	//这里的i是从1开始的，
	for (size_t i = 0; i < a.size(); ++i){
		if (a[i - 1] >= a[i]){
			lexico = 0;
			break;
		}
	}

	//这里的i是从0开始的，
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

//2.排列子序列
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	这里注意多给了一个值，是处理越界的情况的比较，具体参考上面
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	读入数组
	int i = 0; 
	for (i = 0; i < n; ++i) 
		cin >> a[i]; 
	i = 0; 
	int count = 0; 
	while (i < n) { 
		 非递减子序列 
		if (a[i] < a[i + 1]) { 
			while (i < n && a[i] <= a[i + 1]) 
				i++; count++; i++; 
		}
		else if (a[i] == a[i + 1]) { 
			i++; 
		}
		else // 非递增子序列 
		{ 
			while (i < n && a[i] >= a[i + 1]) 
				i++; count++; i++;
		}
	}
	cout << count << endl; 
	system("pause");
	return 0;
}