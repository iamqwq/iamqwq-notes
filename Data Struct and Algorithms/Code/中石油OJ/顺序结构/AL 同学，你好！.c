#include <stdio.h>
#include <string.h>

int main() {
	char str[20];
	char grade[4] = {0};
	char _class[4] = {0};
	
	scanf("%s", str);
	
	int i;
	for(i = 0; i < strlen(str); i++) {
		if(i >= 0 && i < 2) {
			grade[strlen(grade)] = str[i];
		}
		if(i >= 6 && i < 8) {
			_class[strlen(_class)] = str[i];
		}
	}
	
	printf("%s%s", grade, _class);
}
