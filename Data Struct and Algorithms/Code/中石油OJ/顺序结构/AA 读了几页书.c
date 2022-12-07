#include <stdio.h>

int main() {
	int x, m, n;
	int p = 0;
	
	scanf("%d %d %d", &x, &m, &n);
	
	int i;
	for(i = 0; i < n; i++) {
		p += x;
		x += m;
	}
	
	printf("%d", p);
}
