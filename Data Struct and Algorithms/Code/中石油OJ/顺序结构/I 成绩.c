#include <stdio.h>

int main() {
	int a, b, c;
	double score;
	
	scanf("%d %d %d", &a, &b, &c);
	score = a * 0.2 + b * 0.3 + c * 0.5;
	
	printf("%d", (int)score);
}
