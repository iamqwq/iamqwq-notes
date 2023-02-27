#include <stdio.h>
#include <math.h>


int isEqual(long long int a, long long int b) {
	if(a == b) {
		return 1;
	} else {
		return 0;
	}
}

// 116 -> 611
long long int exchange(long long int n, int digits) {
	n /= 10;
	n += 6 * pow(10, digits);
	return n;
}

int main() {
	
	long long int n = 16;
	short count = 0;
	short digits = 1;
	short timesOfTen = 1;
	
	// 4 * n != exchanged n. Then go on.
	for(timesOfTen = 1; 1; ++timesOfTen) {
		int t = exchange(n, digits);
		if(isEqual(4 * n, changedN)) {
			printf("n:%lld changedN:%lld 4*n:%lld\n", n, changedN, 4 * n);
		}
		n += 10;
		if(pow(10, digits) <= timesOfTen) {
			++digits;
		}
	}
	
	return 0;
} 

