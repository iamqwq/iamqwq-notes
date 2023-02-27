#include <stdio.h>

int main() {
	
	unsigned long long int x;
	unsigned long long int y;
	char sign;
	unsigned long long int result;
	
	scanf("%lld%lld\n%c", &x, &y, &sign);
	
	if(sign == '+') {
		result = x + y;
	} else if(sign == '-') {
		result = x - y;
	}
	
	printf("%lld", result);
}
