#include <stdio.h>

int main() {
	int m, a, b;
	int aa = 0, bb = 0;
	
	scanf("%d %d %d", &m, &a, &b);
	
	int i;
	for(i = 0; aa + bb < m; i++) {
		aa += a; bb += b;
	}
	
	printf("%d", i);
}
