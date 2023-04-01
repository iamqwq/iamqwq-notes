#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "suffix.h" 

/*
	预设中缀表达式为字符串，求中缀表达式的结果 
	思路： 
	因为中缀表达式直接进行计算是困难的，所以 
	1. 首先将中缀表达式转换为后缀表达式 
	2. 对后缀表达式进行求值 
	两步均在 suffix.h 中实现 并且均使用堆栈实现 
*/

int main() {

	char s[] = "12 + (9 - 19 * 3) * 9 / 3";
	printf("Original Expression : %s\n", s);
	
	infixConvertToSuffix(s);
	printf("Suffix Expression : %s\n\n\n", s);
	
	printf("\n\nresult : %d", calculateSuffix(s));
	
}
