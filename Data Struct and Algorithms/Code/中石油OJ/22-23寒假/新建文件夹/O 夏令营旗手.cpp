#include <stdio.h>

int main() {
	
	int sAmount;			// Amount of students.
	int t[10000];
	int result = 0;			// Students who were finally selected.
	
	scanf("%d", &sAmount);
	
	// Find prime numbers.
	int count = 1;
	for(int i = 2; i <= sAmount; ++i) {
		int flag = 1;
		for(int j = 2; j < i; ++j) {
			if(i % j == 0) {
				flag = 0;
				break;
			}
		}
		// Add count to prime numbers.
		if(flag) {
			t[count - 1] = i + count;
			++count;
		}
	}
	
	// Find prime numbers in array t.
	for(int i = 0; i < count - 1; ++i) {
		int flag = 1;
		for(int j = 2; j < t[i]; ++j) {
			if(t[i] % j == 0) {
				flag = 0;
				break;
			}
		}
		// Sum.
		if(flag) {
			result += t[i];
		}
	}

	result %= sAmount + 1;
	
	printf("%d", result);
}
