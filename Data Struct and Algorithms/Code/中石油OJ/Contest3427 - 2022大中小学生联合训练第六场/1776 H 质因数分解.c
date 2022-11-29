/*题目描述
已知正整数n是两个不同的质数的乘积，试求出较大的那个质数。*/
/*输入
输入只有一行，包含一个正整数n。6 ≤ n ≤ 2*109*/
/*输出
输出只有一行，包含一个正整数p，即较大的那个质数。*/
/*
样例输入 Copy
21
样例输出 Copy
7
*/
#include <stdio.h>

int main() {
	int flag;
	long long int n;
	scanf("%lld", &n);
	
	
	long long int i, j;
	for(i = 2; i < n; i++) {
		flag = 1;
		for(j = 2; j < i; j++) {
			if(i % j == 0) {
				flag = 0;
				break;
			}
		}
		if(flag == 1) {
			long long int t1 = i;
			long long int t2 = n / t1;
			if(t1 * t2 != n) {
				continue;
			} else {
				printf("%lld", t2);
				break;
			}
		}
	}
}
