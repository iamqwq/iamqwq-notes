#include <stddef.h>

int getPriority(char c) {
	if(c == '/' || c == '*' || c == '%') {
		return 3;
	} else if(c == '+' || c == '-') {
		return 4;
	}else if(c == 0) {
		return NULL;
	}
}
