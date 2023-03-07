#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	long long int n;
	scanf("%lld", &n);
	
	int maxSquare;
	for(int i = 1; i < n; ++i) {
		if(i * i == n) {
			maxSquare = i;
			break;
		}
	}
	
	printf("%d", maxSquare);
	
}
