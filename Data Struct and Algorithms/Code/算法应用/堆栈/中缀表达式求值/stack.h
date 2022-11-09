#include <stddef.h>


typedef struct Stack {
	int *head;
	int top;
	int size;
} Stack;

Stack createStack(int n) {
	Stack s;
	s.head = (int *)malloc(n * sizeof(int));
	s.size = n;
	s.top = -1;
	return s;
}

int isEmpty(Stack s) {
	if(s.top == -1) {
		return 1;
	} else {
		return NULL;
	}
}

void push(Stack *s, int data) {
	if(s->top >= s->size - 1) {
		// printf("Stack Full");
		return;
	} else {
		*(s->head + (++s->top)) = data;
	}
}

int pop(Stack *s) {
	if(s->top == -1) {
		// printf("Stack Empty");
		return 0;
	} else {
		return *(s->head + (s->top--));
	}
}

