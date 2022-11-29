/*题目描述
试计算在区间 1 到 n 的所有整数中，数字 x （0 ≤ x ≤ 9）共出现了多少次？例如，在 1到 11 中，即在 1、2、3、4、5、6、7、8、9、10、11 中，数字 1 出现了 4 次。*/
/*输入
输入共 1 行，包含 2 个整数 n、x，之间用一个空格隔开。1≤n≤1,000,000 ，0≤x≤9*/
/*输出
输出共 1 行，包含一个整数，表示 x 出现的次数。*/
/*
样例输入 Copy
11 1
样例输出 Copy
4
*/


#include <stdio.h>
#include <string.h>

int main() {
	int counter[10] = {0};
	int n, x;
	
	scanf("%d %d", &n, &x);
	
	int i;
	for(i = 1; i <= n; i++) {
		int t = i;
		while(t != 0) {
			if(t % 10 == x) {
				counter[x]++;
			}
			t /= 10;
		}
	}
	printf("%d", counter[x]);
}
