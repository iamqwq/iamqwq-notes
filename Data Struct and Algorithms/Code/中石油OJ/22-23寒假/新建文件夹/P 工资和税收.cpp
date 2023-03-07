#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	
	long long int n;
	char t[10000];
	string str;
	int memberAmount;
	long long int totalMoney = 0;
	
	scanf("%lld\n", &n);
	getline(std::cin, str);
	scanf("%d", &memberAmount);
	int wages[19];
	
	for(int i = 0; i < memberAmount; ++i) {
		scanf("%s%s%d", t, t, &wages[i]);
		totalMoney += wages[i];
	}
	
	if(totalMoney > n) {
		totalMoney += totalMoney - n;
	}
	printf("%lld", totalMoney);
}
