#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int n; 				// Amount of students.
	scanf("%d", &n);
	int capa[101] = {0};
	
	int target = 0; 	// Questions the students need to do.
	
	for(int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		++capa[t];
		capa[t] %= 2;
	}
	
	int current = 0;
	for(int i = 0; i < 101; ++i) {
		if(capa[i] == 0) {
			continue;
		} else {
			if(current == 0) {
				current = i;
				continue;
			} else {
				target += i - current;
				current = 0;
			}
		}
	}
	
	printf("%d", target);
	
	return 0;
}
