#include <stdio.h>

int main() {
	
	char X, Y;
	
	scanf("%c %c", &X, &Y);
	
	if(X < Y) {
		printf("<");
	} else if(X > Y) {
		printf(">");
	} else {
		printf("=");
	}
	
	return 0;
}
