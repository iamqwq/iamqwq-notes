#include <stdio.h>

int main() {
	int n;
	int t5, t1, c5, c2, c1;
	
	scanf("%d", &n);
	
	t5 = n / 50; n %= 50;
	t1 = n / 10; n %= 10;
	c5 = n / 5; n %= 5;
	c2 = n / 2; n %= 2;
	c1 = n / 1;
	
	printf("%d\n%d\n%d\n%d\n%d", t5, t1, c5, c2, c1); 
}
