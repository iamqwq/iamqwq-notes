// Selection Sort

#include <stdio.h>

int main() {
	int num[10] = {1, 7, 5, 2, 4, 3, 9, 8, 6, 10};
	int i, j;
	int t;
	int min;
	
	for(i = 0; i < 10; i++) {
		min = i;
		for(j = i; j < 10; j++) {
			if(num[j] < num[min]) {
				min = j;
			}
		}
		t = num[i]; num[i] = num[min]; num[min] = t;
	}
	
	for(i = 0; i < 10; i++) {
		printf("%d ", num[i]);
	}
} 
