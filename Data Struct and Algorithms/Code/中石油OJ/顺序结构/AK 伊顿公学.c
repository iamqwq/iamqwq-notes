#include <stdio.h>

int main() {
	int m, n;
	
	scanf("%d,%d", &m, &n);
	
	printf("%d", m * 0.01 * n - (int)(m * 0.01 * n) > 0 ? (int)(m * 0.01 * n + 1) : (int)(m * 0.01 * n));
}
