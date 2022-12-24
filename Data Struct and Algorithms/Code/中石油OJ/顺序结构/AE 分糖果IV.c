#include <stdio.h>

int main() {
	int a, b, c, d, e;
	int t;
	
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	t = a /= 3; e += t; b += t;
	t = b /= 3; a += t; c += t;
	t = c /= 3; b += t; d += t;
	t = d /= 3; c += t; e += t;
	t = e /= 3; d += t; a += t;
	
	printf("%d %d %d %d %d", a, b, c, d, e);
}
