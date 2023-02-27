#include <stdio.h>
#include <math.h>

int main() {
	
	int a;
	
	scanf("%lld", &a);
	
	int t = 1;
	int sum = 1;
	int count = 1;
	while(sum <= a) {
		t *= 3;
		++count;
		sum += t;
	}
	
	printf("%d", count);
	
	return 0;
}
