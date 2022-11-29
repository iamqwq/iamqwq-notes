#include <stdio.h>

int main() {
	char c[10];
	int i;
	for(i = 0; i < 3; i++) {
		scanf("%c", &c[i]);
	}
	c[i] = '\0';
	puts(c);
} 
