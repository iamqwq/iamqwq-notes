#include <stdio.h>
#include <stdlib.h>

typedef struct Row {
	int i;
	int zp;
} Row;

void BubbleZPSort(Row* arr, int size) {
	for(int i = 0; i < size - 1; ++i) {
		for(int j = i + 1; j < size; ++j) {
			if(arr[i].zp > arr[j].zp) {
				Row t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

void BubbleIndexSort(Row* arr, int start, int end) {
	for(int i = start; i <= end - 1; ++i) {
		for(int j = i + 1; j <= end; ++j) {
			if(arr[i].i > arr[j].i) {
				Row t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

void DicSort(Row* arr, int size) {
	int start = -1, end = -1;
	int flag = 0;
	for(int i = 0; i < size; ++i) {
		if(!flag && arr[i].zp == arr[i + 1].zp) {
			start = i;
			flag = 1;
		} else if(flag && arr[i].zp != arr[i + 1].zp) {
			end = i;
			flag = 0;
		}
		if(start != -1 && end != -1) {
			BubbleIndexSort(arr, start, end);
			start = end = -1;
		}
	}
}

int main() {
	
	int r; // Rows.
	int c; // Columns.
	int k; // Bombs.
	int n; // Zombies.
	
	int int_rows[1000] = {0}; // Rows.
	
	scanf("%d %d %d %d", &r, &c, &k, &n);
	
	int rzp = 0; // Number of rows of zombies present.
	int x, y;
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		if(int_rows[x]++ == 0) ++rzp;
	}
	
	int count = 0;
	Row* rows = (Row*) malloc(rzp * sizeof(Row));
	for(int i = 0; i < 1000; ++i) {
		if(int_rows[i] == 0) continue;
		rows[count].i = i;
		rows[count].zp = int_rows[i];
		++count;
	}
	
	BubbleZPSort(rows, rzp);
	DicSort(rows, rzp);
	
	
	Row* results = (Row*) malloc(rzp * sizeof(Row));
	int current;
	for(int i = 0; i < k; ++i) {
		current = k - i;
		for(int j = 0; j < current; ++j) {
			if()
		}
	} 
	
	

	for(int i = 0; i < rzp; ++i) {
		printf("%d %d\n", rows[i].i, rows[i].zp);
	}
	
	return 0;
} 
