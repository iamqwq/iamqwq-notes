#include <stdio.h>

int main() {
	int x, y, z;
	double avg;
	
	scanf("%d %d %d", &x, &y, &z);
	avg = (x + y + z) / 3.0;
	
	printf("%.5lf", avg);
}
