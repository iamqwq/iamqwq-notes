/*��Ŀ����:
����һ���������뽫��������λ�����ַ�ת�õ�һ������������ҲӦ���������ĳ�����ʽ�������Ǹ�����ԭ��Ϊ�㣬����ת��õ������������λ���ֲ�ӦΪ�㡣*/
/*����:
���빲 1 �У�һ������N��-1,000,000,000 �� N�� 1,000,000,000*/
/*���:
����� 1 �У�һ����������ʾ��ת���������*/
/*
�������� Copy
123
������� Copy
321
*/

#include <stdio.h>
#include <string.h>

int main() {
	char N[20];
	scanf("%s", N);
	int i;
	int isFirst = 1;
	int isSignOut = 0;
	if(strlen(N) == 1 && N[0] == '0') {
		printf("0");
	} else {
		for(i = strlen(N) - 1; i >= 0; i--) {
			if(!isSignOut && N[0] == '-') {
				printf("-");
				isSignOut = 1;
			} else if(isSignOut && N[i] == '-') {
				continue;
			}
			if(isFirst && N[i] == '0') {
				continue;
			} else {
				isFirst = 0;
			}
			printf("%c", N[i]);
		}
	}
	
} 
