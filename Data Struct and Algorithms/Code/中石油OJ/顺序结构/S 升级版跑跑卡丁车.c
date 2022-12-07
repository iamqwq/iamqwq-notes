#include <stdio.h>

int main() {
	int startH, endH, startM, endM;
	int tH, tM;
	int hits;
	
	scanf("%d:%d %d:%d %d", &startH, &startM, &endH, &endM, &hits);
	
	tM = endM - startM;
	tH = endH - startH;
	tM = tM < 0 ? (tH--, tM += 60) : tM;
	tH = tH < 0 ? tH += 24 : tH;
	tM += tH * 60;
	
	printf("%d", tM + hits * 20);
}
