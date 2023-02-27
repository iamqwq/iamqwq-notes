#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int r; // Rows.
	int c; // Columns.
	int n; // Students.
	
	scanf("%d%d%d", &r, &c, &n);
	
	int* tn = (int*) malloc(r * c * sizeof(int));

	for(int i = 0; i < n; ++i) {
		scanf("%d", &tn[i]);
	}
	
	int tr;
	int tc;
	for(int i = 0; i < n; ++i) {
		tr = tn[i] % c != 0 ? tn[i] / c + 1 : tn[i] / c;
		tc = tr % 2 != 0 ? (tn[i] % c ? tn[i] % c : c) : c - (tn[i] % c ? tn[i] % c : c) + 1;
		printf("%d %d\n", tr, tc);
	}
	
	return 0;
}
