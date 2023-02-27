#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertChar(char* s, int i, char c) {
	int len = strlen(s);
	for(int j = len; j >= i; --j) {
		s[j + 1] = s[j];
	}
	s[i] = c;
	s[len + 1] = '\0';
}

void RemoveChar(char* s, int i) {
	int len = strlen(s);
	for(int j = i; j < len - 1; ++j) {
		s[j] = s[j + 1]; 
	}
	s[len - 1] = '\0';
}

int main() {
	
	char s[30];
	char p;
	
	scanf("%s", s);
	getchar();
	scanf("%c", &p);
	
	int isRemoved = 0;
	for(int i = 0; i < strlen(s) - 1; ++i) {
		if(s[i] - '0' < s[i + 1] - '0') {
			RemoveChar(s, i);
			isRemoved = 1;
			break;
		}
	}
	if(!isRemoved) {
		int len = strlen(s);
		s[len - 1] = '\0';
	}
	
	int isInserted = 0;
	for(int i = 0; i < strlen(s); ++i) {
		if(p - '0' > s[i] - '0') {
			InsertChar(s, i, p);
			isInserted = 1;
			break;
		}
	}
	if(!isInserted) {
		int len = strlen(s);
		s[len] = p;
		s[len + 1] = '\0';
	}
	
	puts(s);
} 
