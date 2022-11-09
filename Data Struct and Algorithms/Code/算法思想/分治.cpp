#include <stdio.h>
#define N 8

int maxSubseq(int *a, int left, int right) { 
	// exit condition.
	if(left == right) {
		printf("%d %d\n", left, a[left]);
		if(a[left] < 0) return 0;
		else return a[left];
	}
	
	// caculate the largest subseq. (left and right)
	int center = (left + right) / 2;
	int leftSum = maxSubseq(a, left, center);
	int rightSum = maxSubseq(a, center + 1, right);
	printf("leftright: %d %d\n", left, right);
	printf("leftrightSum: %d %d\n", leftSum, rightSum); 
	int t, s1, s2;
	t = s1 = s2 = 0;
	for(int i = left; i < right; i++) {
		t += a[i];
		if(t > s1) {
			s1 = t;
		}
	}
	t = 0;
	for(int i = right; i > left; i--) {
		t += a[i];
		if(t > s2) {
			s2 = t;
		}
	}
	
	// caculate the largest subseq. (currentseq)
	int sum = s1 >= s2 ? s1 : s2;
	printf("sum: %d\n", sum);
	if(sum >= leftSum && sum >= rightSum) {
		printf("return: %d\n\n", sum);
		return sum;
	} else if(leftSum > rightSum) {
		printf("return: %d\n\n", s1);
		return s1;
	} else {
		printf("return: %d\n\n", s2);
		return s2;
	}
} 

int main() {
	int a[N] {4, -3, 5, -2, -1, 2, 6, -2};
	
	printf("%d", maxSubseq(a, 0, N - 1));
	
	return 0;
} 
