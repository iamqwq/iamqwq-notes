#include <stdio.h>

int main() {
	int a, b;
	int rabbit, chick;
	
	scanf("%d %d", &a, &b);
	
	rabbit = (b - a * 2) / 2;
	chick = a - rabbit;
	
	printf("rabbit=%d,chicken=%d", rabbit, chick);
}
