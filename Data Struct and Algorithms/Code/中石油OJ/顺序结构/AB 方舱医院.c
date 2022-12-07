#include <stdio.h>

int main() {
	int a, b, c;
	int t;
	int n;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if(a < b) {
		t = a; a = b; b = t;
	}
	if(a > c && b > c) {
		a = (a / c) * c;
		b = (b / c) * c;
	} 
	n = a * b / (c * c);
	
	printf("%d", n);
}
