#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	long long int n;
	scanf("%lld", &n);
	
	for(long long int i = n; i > 0; --i) {
		if(sqrt(i) == (int) sqrt(i)) {
			printf("%lld", i);
			break;
		}
	}
	
}
