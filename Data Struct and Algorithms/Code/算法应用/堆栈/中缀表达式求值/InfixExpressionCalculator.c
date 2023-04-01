#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "suffix.h" 

/*
	Ԥ����׺���ʽΪ�ַ���������׺���ʽ�Ľ�� 
	˼·�� 
	��Ϊ��׺���ʽֱ�ӽ��м��������ѵģ����� 
	1. ���Ƚ���׺���ʽת��Ϊ��׺���ʽ 
	2. �Ժ�׺���ʽ������ֵ 
	�������� suffix.h ��ʵ�� ���Ҿ�ʹ�ö�ջʵ�� 
*/

int main() {

	char s[] = "12 + (9 - 19 * 3) * 9 / 3";
	printf("Original Expression : %s\n", s);
	
	infixConvertToSuffix(s);
	printf("Suffix Expression : %s\n\n\n", s);
	
	printf("\n\nresult : %d", calculateSuffix(s));
	
}
