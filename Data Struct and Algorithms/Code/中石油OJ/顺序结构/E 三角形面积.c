#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, area, p;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	
	p = (a + b + c) / 2;
	area = sqrt(p * (p - a) * (p - b) * (p - c));
	
	printf("%.4lf", area); 
	
}
