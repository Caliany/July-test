//��ϸ����һ�¿����������������
#include<stdio.h>

int main(){
	char str[] = "glad to test something!";
	char *p = str;
	p++;
	int *p1 = reinterpret_cast<int *>(p);
	p1++;
	p = reinterpret_cast<char *>(p1);
	printf("result is %s\n", p);

	//�����result is to test something
	return 0;
}