#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
	char *head;
	int top;
	int size;
} Stack;

Stack createStack(int n) {
	Stack s;
	s.head = (char *)malloc(n * sizeof(char));
	s.size = n;
	s.top = -1;
	return s;
}

int isEmpty(Stack s) {
	if(s.top == -1) {
		return 1;
	} else {
		return 0;
	}
}

void push(Stack *s, char data) {
	if(s->top >= s->size - 1) {
		printf("Stack Full");
		return;
	} else {
		*(s->head + (++s->top)) = data;
	}
}

char pop(Stack *s) {
	if(s->top == -1) {
		//printf("Stack Empty");
		return NULL;
	} else {
		return *(s->head + (s->top--));
	}
}

int getPriority(char c) {
	if(c == ')') {
		return 1;
	}else if(c == '/' || c == '*' || c == '%') {
		return 3;
	} else if(c == '+' || c == '-') {
		return 4;
	} else if(c == '(') {
		return 15;
	} else if(c == 0) {
		return NULL;
	}
}

void convertToSuffix(char *str) {
	// 输入的字符串
	// 运算数直接输出
	// 运算符优先级低于栈顶则压栈
	// 运算符优先级高于栈顶则弹出输出 再次比较直到低于为止
	
	Stack s = createStack(10); 
	int currentP;
	int stackTopP;
	char t;
	
	int i;
	for(i = 0; i < strlen(str); i++) {
		// 数字 
		if(*(str + i) >= '0' && *(str + i) <= '9') {
			printf("%c", *(str + i));
		} else {
			// 运算符
			currentP = getPriority(*(str + i));
			stackTopP = getPriority(t = pop(&s));
			if(currentP < stackTopP || stackTopP == 0) {
				if(stackTopP != 0) {
					push(&s, t);
				}
				push(&s, *(str + i));
			} else {
				char ttop = *(str + i);
				printf("%c", t);
				while(1) {
					currentP = stackTopP;
					stackTopP = getPriority(t = pop(&s));
					if(currentP >= stackTopP && stackTopP != NULL) {
						printf("%c", t);
					} else {
						push(&s, t);
						push(&s, ttop);
						break;
					}
				}
			}
		}
	}
	while(!isEmpty(s)) {
		printf("%c", pop(&s));
	}
} 	

int main() {

	char s[] = "7/1+2*5/100";
	convertToSuffix(s);
	
} 
