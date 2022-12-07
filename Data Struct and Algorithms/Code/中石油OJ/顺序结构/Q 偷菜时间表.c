#include <stdio.h>

int main() {
	int currentH, currentM, grouthH, grouthM;
	int resultH, resultM;
	
	scanf("%d:%d %d:%d", &currentH, &currentM, &grouthH, &grouthM);
	
	if(currentM + grouthM >= 60) {
		grouthH++;
	}
	resultM = (currentM + grouthM) % 60;
	resultH = (currentH + grouthH) % 24;
	
	printf("%02d:%02d", resultH, resultM);
}
