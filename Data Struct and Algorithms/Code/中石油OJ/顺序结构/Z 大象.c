#include <stdio.h>

int main() {
	int x;
	int step = 0;
	
	scanf("%d", &x);
	
	if(x % 5) {
		step++;
	}
	step += x / 5;
	printf("%d", step);
	
}
