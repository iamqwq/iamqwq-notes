#include <stdio.h>

int main() {
	
	int n;
	int t[1000000];
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
	}
	
	double walk, bike;
	for(int i = 0; i < n; ++i) {
		walk = t[i] / 1.2;
		bike = t[i] / 3.0 + 27 + 23;
		printf("%s\n", walk <= bike ? (walk == bike ? "All" : "Walk") : "Bike");
	}
	
	return 0;
}
