#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isGood(int* arr, int size) {
	for(int i = 0; i < size - 1; ++i) {
		if(abs(arr[i] - arr[i + 1]) > 1) {
			return 0;
		}
	}
	return 1;
}

void BubbleSort(int* arr, int size) {
	for(int i = 0; i < size - 1; ++i) {
		for(int j = i + 1; j < size; ++j) {
			if(arr[i] > arr[j]) {
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

int main() {
	
	int t;		// Groups.
	scanf("%d", &t);
	int* tr		// Result.
		= (int*) malloc(t * sizeof(int)); 
		
	
	for(int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		int* arr = (int*) malloc(n * sizeof(int));
		for(int j = 0; j < n; ++j) {
			scanf("%d", &arr[j]);
		}
		BubbleSort(arr, n);
		tr[i] = isGood(arr, n);
		free(arr);
	}
	
	for(int i = 0; i < t; ++i) {
		printf("%s\n", tr[i] ? "YES" : "NO");
	}
	
}
