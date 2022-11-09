#include <stdio.h>

int fun(int n) {
	int i, j;
	int tag;
	int i2, j2;
	int tag2;
	int flag;
	int count = 0;
	
	for(i = 2; i <= n; i++) {
		tag = 1;
		flag = 0;
		for(j = 2; j < i; j++) {
			if(i % j == 0) {
				tag = 0;
				break;
			}
		}
		if(tag == 1) {
			for(i2 = 2; i2 <= n; i2++) {
				tag2 = 1;
				for(j2 = 2; j2 < i2; j2++) {
					if(i2 % j2 == 0) {
						tag2 = 0;
						break;
					}
				}
				if(tag2 == 1) printf("%d is whatever\n", i2);
				if(tag2 == 1 && i * i2 == n) {
					printf("-- %d %d\n", i, i2);
					if(flag == 0) {
						count += 2;
						flag++;
					} else {
						count++;
					}
				}
			}
		}
	}
	
	return count;
}

int main() {
	int n;
	do {
		scanf("%d", &n);
		printf("%d\n", fun(n));
	} while(n != 0);
}
