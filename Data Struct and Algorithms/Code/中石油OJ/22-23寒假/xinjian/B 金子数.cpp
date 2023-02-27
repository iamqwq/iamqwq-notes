#include <stdio.h>

int main() {
	
	int n; // Roads.
	int m; // Numbers.
	
	scanf("%d %d", &n, &m);
	
	int weights[100];
	int heaviest;
	
	for(int i = 0; i < n; ++i) {
		int weight = 0;
		int t;
		for(int j = 0; j < m; ++j) {
			scanf("%d", &t);
			if(t % 8 == 0) {
				weight += t;
			}
		}
		weights[i] = weight;
		if(i == 0 || weight > weights[heaviest]) {
			heaviest = i;
		}
	}
	
	printf("%d", heaviest + 1);
	
	return 0;
}
