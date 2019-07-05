/*
测试用例性能之测试用例：
性能测试、压力测试、负载测试 、强度测试、稳定性测试、健壮性测试、功能测试、接口测试...
这么多眼花缭乱的名词，反正我是已经晕了，傻傻分不清！
功能测试：
接口测试：
性能测试：
用户界面测试：
安装/反安装测试：
文档测试：
测试阶段：单元测试->集成测试->系统测试—>验收测试。
*/
//1.输出一个数字，表示把字符串B插入到字符串A之后构成一个回文数的方法数。
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 200

bool IsPalin(char * str, int length)
{
	int cnt = 0;
	for (int i = 0; i < (length / 2); i++)
	{
		if (str[i] != str[length - i - 1])
		{
			++cnt;
			
		}
			break;
	}
	if (cnt == 0)
		return false;
	else
		return true;
}

int main(){
	char *A = (char *)malloc(100);//给A申请空间
	char *B = (char *)malloc(100);
	int count = 0;
	cin >> A;
	cin >> B;

	int ALen = strlen(A);//标记A的长度
	int BLen = strlen(B);
	for (int i = 0; i <= ALen; i++)
	{
		char *C = (char *)malloc(100);
		if (i == 0)
		{
			memcpy(C, B, BLen);
			memcpy(C + BLen, A + i, ALen);
			if (IsPalin(C, strlen(C)))
				++count;
		}
		else
		{
			memcpy(C, A, i);
			memcpy(C + i, B, BLen);
			memcpy(C + i + BLen, A + i, ALen - i);
			if (IsPalin(C, ALen + BLen))
				++count;
		}
		free(C);
		C = NULL;
		cout << count << endl;
		free(A);//释放空间
		free(B);
		system("pause");
		return 0;
	}
}