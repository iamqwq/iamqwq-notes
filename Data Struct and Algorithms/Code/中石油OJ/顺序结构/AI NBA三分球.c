#include <stdio.h>

int main() {
	int M, N;
	
	scanf("%d,%d", &M, &N);
	
	int i;
	for(i = 0; M <= N; i++) {
		M += 4;
	}
	printf("%d", i);
}
