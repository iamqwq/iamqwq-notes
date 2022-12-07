#include <stdio.h>

int main() {
	int N;
	double t;
	
	scanf("%d", &N);
	
	t = N * 1.5;
	t = t - (int)t != 0 ? (int)t + 1 : t; 
	
	printf("%d", (int)t);
}
