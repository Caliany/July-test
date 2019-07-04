//1.输入一个整数，求n阶方阵的和
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstdio>

using namespace std;

int main(){

	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int x; scanf("%d", &x);
			sum += x;
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}

/*
1. 标题：组队竞赛 | 时间限制：1秒 | 内存限制：32768K 
牛牛举办了一次编程比赛, 参加比赛的有3*n个选手, 每个选手都有一个水平值a_i.现在要将这些选手进行组队, 一 共组成n个队伍, 即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。 
例如 : 一个队伍三个队员的水平值分别是3, 3, 3.那么队伍的水平值是3 一个队伍三个队员的水平值分别是3, 2, 3.那么队伍的水平值是3 一个队伍三个队员的水平值分别是1, 5, 2.那么队伍的水平值是2 为了让比赛更有看点, 牛牛想安排队伍使所有队伍的水平值总和最大。 
如样例所示 : 如果牛牛把6个队员划分到两个队伍 如果方案为:
team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
而如果方案为: team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10. 没有比总和为10更大的方案,所以输出10.

输入描述： 输入的第一行为一个正整数n(1 ≤ n ≤ 10^5) 第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.
输出描述： 输出一个整数表示所有队伍的水平值总和最大值. 示例1: 输入25 2 8 5 1 5 输出10
*/
#include<iostream> 
#include<algorithm> 
#include<vector> 
using namespace std; 
int main() {
	//IO型OJ可能会有多组测试用例，所以这里要持续接收输入多组测试用例。 
	int n; 
	while (cin >> n) { 
		long long sum = 0; 
		vector<int> a; 
		a.resize(3*n); 
		for (int i = 0; i < (3 * n); i++) 
		{ 
			cin >> a[i]; 
		}
	/*
	排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可，
	相当下标为[0,n-1]的n个数做每组的最左边的数，剩下的2个数据两个为一组， 
	大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来
	*/
		std::sort(a.begin(), a.end()); 
		for (int i = n; i <= 3 * n - 2; i += 2)
		{ 
			sum += a[i]; 
		}
		cout << "sum=" << sum << endl;
	} 
}

/*
2. 标题：删除公共字符 | 时间限制：1秒 | 内存限制：32768K 
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.” 
输入描述: 每个测试输入包含2个字符串 
输出描述: 输出删除后的字符串 
示例1 : 输入They are students.aeiou 
输出Thy r stdnts.
*/

#include<iostream> 
#include<string> 
using namespace std; 
int main()
{	
	// 注意这里不能使用cin接收，因为cin遇到空格就结束了。 
	// oj中IO输入字符串最好使用getline。 
	string str1,str2; 
	//cin>>str1; 
	//cin>>str2; 
	getline(cin, str1); 
	getline(cin, str2); 
	// 使用哈希映射思想先str2统计字符出现的次数 
	int hashtable[256] = {0}; 
	for(size_t i = 0; i < str2.size(); ++i) 
	{ 
		hashtable[str2[i]]++; 
	}
	// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在 
	// str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i) 
	// 因为边遍历，边erase，容易出错。 
	string ret; 
	for(size_t i = 0; i < str1.size(); ++i) 
	{ 

		if(hashtable[str1[i]] == 0)
		ret += str1[i]; 
	}

	cout << ret << endl; 
	return 0; 
}