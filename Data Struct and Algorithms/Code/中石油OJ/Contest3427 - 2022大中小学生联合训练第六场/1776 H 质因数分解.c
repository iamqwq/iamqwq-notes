/*��Ŀ����
��֪������n��������ͬ�������ĳ˻���������ϴ���Ǹ�������*/
/*����
����ֻ��һ�У�����һ��������n��6 �� n �� 2*109*/
/*���
���ֻ��һ�У�����һ��������p�����ϴ���Ǹ�������*/
/*
�������� Copy
21
������� Copy
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
