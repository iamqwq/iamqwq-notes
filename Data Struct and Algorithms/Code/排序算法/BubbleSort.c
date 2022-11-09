// Bubble Sort

#include <stdio.h>

int main() {
	int num[10] = {1, 7, 5, 2, 4, 3, 9, 8, 6, 10};
	int i, j;
	int t;
	
	for(i = 0; i < 10; i++) {
		for(j = 0; j < i - 1; j++) {
			if(num[i] < num[j]) {
				t = num[i]; num[i] = num[j]; num[j] = t;
			}
		}
	}
	
	for(i = 0; i < 10; i++) {
		printf("%d ", num[i]);
	}
} 
