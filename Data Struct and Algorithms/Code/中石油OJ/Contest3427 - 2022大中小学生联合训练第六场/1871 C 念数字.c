/*����һ�����������ÿ�����ֶ�Ӧ��ƴ����������Ϊ����ʱ���������fu���֡�ʮ�����ֶ�Ӧ��ƴ�����£�*/
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
/*����
������һ���и���һ���������磺1234��
��ʾ�������������������������*/
/*���
������������Ӧ��ƴ����ÿ�����ֵ�ƴ��֮���ÿո�ֿ�����ĩû�����Ŀո���yi er san si��*/
/*
�������� Copy
-600
������� Copy
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
