// Insertion Sort

#include <stdio.h>

int main() {
	int num[10] = {1, 7, 5, 2, 4, 3, 9, 8, 6, 10};
	int i, j;
	int key;
	
	for(i = 1; i < 10; i++) {
		key = num[i];
		j = i - 1;
		while(j >= 0 && num[j] > key) {
			num[j + 1] = num[j];
			j--;
		}
		num[j + 1] = key;
	}
	
	for(i = 0; i < 10; i++) {
		printf("%d ", num[i]);
	}
}
