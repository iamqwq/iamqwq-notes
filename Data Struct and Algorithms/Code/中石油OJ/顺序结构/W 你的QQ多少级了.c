#include <stdio.h>

int main() {
	int days;
	int levels;
	int i; 
	
	scanf("%d", &days);
	
	for(i = 0; 1; i++) {
		if(i * i + i * 4 > days) {
			break;
		}
	}
	
	printf("%d", i - 1);
}
