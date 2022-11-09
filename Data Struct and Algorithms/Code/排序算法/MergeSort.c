// Merge Sort

#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right) {
	int i = left, j = mid + 1;
	int index = 0;
	int *temp = (int *)malloc((right - left + 1) * sizeof(int));
	
	while(i <= mid && j <= right) {
		if(arr[i] < arr[j]) {
			temp[index++] = arr[i++]; 
		} else {
			temp[index++] = arr[j++];
		}
	}
	while(i <= mid) {
		temp[index++] = arr[i++];
	}
	while(j <= right) {
		temp[index++] = arr[j++];
	}
	for(i = 0; i < index; i++) {
		arr[left + i] = temp[i];
	}
	free(temp);
}

void mergeSort(int *arr, int left, int right) {
	if(right - left <= 0) {
		return;
	} else {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
} 

int main() {
	int num[10] = {1, 7, 5, 2, 4, 3, 9, 8, 6, 10};
	
	mergeSort(num, 0, 9);
	
	int i;
	for(i = 0; i < 10; i++) {
		printf("%d ", num[i]);
	}
}


