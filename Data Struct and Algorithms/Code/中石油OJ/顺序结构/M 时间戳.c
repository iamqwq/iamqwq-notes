#include <stdio.h>

int main() {
//	while(1) {
		long int n;
		int year = 2011, month = 1, day = 1;
		
		scanf("%d", &n);
		
		n /= 60;
		n /= 60;
		n /= 24; // days
		day += n;
		
		month += day % 30 == 0 ? ((day / 30) >= 1 ? (day / 30) - 1 : 0) : (day / 30); day %= 30;
		year += month % 12 == 0 ? ((month / 12) >= 1 ? (month / 12) - 1 : 0) : (month / 12); month %= 12;
		
		printf("%d %d %d", year, month == 0 ? 12 : month, day == 0 ? 30 : day);
//	}
	// 86400 a day 2592000 a month
}
