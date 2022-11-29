/*题目描述:
给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零。*/
/*输入:
输入共 1 行，一个整数N。-1,000,000,000 ≤ N≤ 1,000,000,000*/
/*输出:
输出共 1 行，一个整数，表示反转后的新数。*/
/*
样例输入 Copy
123
样例输出 Copy
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
