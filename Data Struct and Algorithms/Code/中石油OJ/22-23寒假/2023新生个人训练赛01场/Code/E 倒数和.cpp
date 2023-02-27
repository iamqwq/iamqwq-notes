#include <stdio.h>

int main() {
	
	int s;
	scanf("%d", &s);
	
	double t = 0;
	int n;
	for(int i = 1; ; ++i) {
		t += 1.0 / i;
		if(t + (1.0 / (i + 1)) > s && t <= s) {
			n = i;
			break; 
		}
	}
	
	printf("%d", n);
}
