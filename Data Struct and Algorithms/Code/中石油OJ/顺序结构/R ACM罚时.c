#include <stdio.h>

int main() {
	int startH, endH, startM, endM;
	int tH, tM;
	int WA;
	
	scanf("%d:%d %d:%d %d", &startH, &startM, &endH, &endM, &WA);
	
	tM = endM - startM;
	tH = endH - startH;
	tM = tM < 0 ? (tH--, tM += 60) : tM;
	tM += tH * 60;
	
	printf("%d", tM + 20 * WA);
}
