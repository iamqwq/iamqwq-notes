#include <stdio.h>

int isHNum(int n) {
	for(int i = 4; i < n; ++i) {
		if(i == 5 || i == 7) {
			continue;
		} else if(n % i == 0) {
			printf("%d", i);
			return 0;
		}
	}
	return 1;
}

int main() {
	
	int n;
	
	scanf("%d", &n);
	
	if(isHNum(n)) {
		printf("yes");
	} else {
		printf("no");
	}
	
	
}
