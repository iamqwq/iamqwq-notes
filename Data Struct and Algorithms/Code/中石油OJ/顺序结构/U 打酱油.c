#include <stdio.h>

int main() {
	int N;
	int t1, t2;
	
	scanf("%d", &N);
	
	N /= 10;
	t1 = N / 5;
	t1 *= 2;
	t2 = N % 5 / 3; 
	
	printf("%d", N + t1 + t2);
}
