#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c;
	double s, p;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	a = sqrt(a);
	b = sqrt(b);
	c = sqrt(c);
	
	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	
	printf("%.2lf", s);
} 
