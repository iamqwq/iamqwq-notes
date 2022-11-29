/*输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出“fu”字。十个数字对应的拼音如下：*/
/*
0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu
*/
/*输入
输入在一行中给出一个整数，如：1234。
提示：整数包括负数、零和正数。*/
/*输出
输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如yi er san si。*/
/*
样例输入 Copy
-600
样例输出 Copy
fu liu ling ling
*/

#include <stdio.h>
#include <string.h>

int main() {
	char *c[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	char N[20];
	scanf("%s", N);
	
	int i;
	for(i = 0; i < strlen(N); i++) {
		if(i != 0) {
			printf(" ");
		}
		if(N[i] == '-') {
			printf("fu");
		} else {
			printf("%s", c[N[i] - '0']);
		}
	}
	
}
