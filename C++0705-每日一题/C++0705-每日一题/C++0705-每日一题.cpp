/*
������������֮����������
���ܲ��ԡ�ѹ�����ԡ����ز��� ��ǿ�Ȳ��ԡ��ȶ��Բ��ԡ���׳�Բ��ԡ����ܲ��ԡ��ӿڲ���...
��ô���ۻ����ҵ����ʣ����������Ѿ����ˣ�ɵɵ�ֲ��壡
���ܲ��ԣ�
�ӿڲ��ԣ�
���ܲ��ԣ�
�û�������ԣ�
��װ/����װ���ԣ�
�ĵ����ԣ�
���Խ׶Σ���Ԫ����->���ɲ���->ϵͳ���ԡ�>���ղ��ԡ�
*/
//1.���һ�����֣���ʾ���ַ���B���뵽�ַ���A֮�󹹳�һ���������ķ�������
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
	char *A = (char *)malloc(100);//��A����ռ�
	char *B = (char *)malloc(100);
	int count = 0;
	cin >> A;
	cin >> B;

	int ALen = strlen(A);//���A�ĳ���
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
		free(A);//�ͷſռ�
		free(B);
		system("pause");
		return 0;
	}
}