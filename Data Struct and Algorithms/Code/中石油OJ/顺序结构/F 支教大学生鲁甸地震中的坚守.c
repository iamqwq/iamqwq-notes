#include <stdio.h>

int main() {
	int hs, ms, h, m;
	int ht, mt;
	
	scanf("%d %d %d %d", &hs, &ms, &h, &m);
	
	ht = (hs + h) % 24;
	mt = (ms + m);
	if(mt >= 60) {
		ht++;
		mt -= 60;
		if(ht >= 24) {
			ht -= 24;
		}
	}
	
	printf("%02d:%02d", ht, mt);
}
