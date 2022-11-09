#include <stdio.h>

void shellSort(int *arr, int length) {
	int gap;
	int i, j, k;
	int temp;
	
	for(gap = length / 2; gap > 0; gap /= 2) {
		for(i = 0; i < gap; i++) {
			for(j = i + gap; j < length; j += gap) {
				if(arr[j] < arr[j - gap]) {
					temp = arr[j];
					k = j - gap;
					while(k >= 0 && temp < arr[k]) {
						arr[k + gap] = arr[k];
						k -= gap;
					}
					arr[k + gap] = temp;
				}
			}
		}
	}
}

int main() {
	
	int num[10] = {1, 7, 5, 2, 4, 3, 9, 8, 6, 10};
	shellSort(num, 10);
	int i;
	for(i = 0; i < 10; i++) {
		printf("%d ", num[i]);
	}
	
}
