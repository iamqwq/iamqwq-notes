#include <stdio.h>

int main() {
	int start, end;
	int dHour, dMin;
	
	scanf("%d %d", &start, &end);
	
	dHour = end / 100 - start / 100;
	dMin = end % 100 - start % 100;
	if(dMin < 0) {
		dMin += 60;
		dHour--;
	}
	
	printf("%d:%02d", dHour, dMin);
}
