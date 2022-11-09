#include <stdio.h>

int main() {
	int l, area;
	
	scanf("%d", &l);
	
	if(l / 4 == l / 4.0) {
		area = (l / 4) * (l / 4);
	} else {
		area = ((l / 2) - (l / 4)) * (l / 4);
	}
	
	printf("%d", area);
	
} 
