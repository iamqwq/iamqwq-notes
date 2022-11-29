#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
	int data;
	struct BTNode *left;
	struct BTNode *right;
} BTNode;

BTNode* addElement(BTNode *bt, int data) {
	if(bt == NULL) {
		bt = (BTNode *)malloc(sizeof(BTNode));
		bt->left = NULL;
		bt->right = NULL;
		bt->data = data;
	} else if(data > bt->data) {
		bt->left = addElement(bt->left, data);
	} else if(data <= bt->data) {
		bt->right = addElement(bt->right, data);
	}
	return bt;
}

typedef struct Stack {
	int top;
	BTNode *head;
	int size;
} Stack;

Stack createStack(int size) {
	Stack s;
	s.head = (BTNode *)malloc(size * sizeof(BTNode));
	s.size = size;
	s.top = -1;
	return s;
}

void push(Stack *s, BTNode node) {
	if(s->top < s->size) {
		s->head[++s->top] = node;
	}
}

BTNode pop(Stack *s) {
	BTNode bt;
	if(s->top > -1) {
		return s->head[s->top--];
	} else {
		return bt;
	}
}

int isStackEmpty(Stack s) {
	return s.top == -1 ? 1 : 0;
}

void printElements(BTNode *bt) {
	if(bt != NULL) {
		printf("%d ", bt->data);
		printElements(bt->left);
		printElements(bt->right);
	}
}

void preOrderTraverse(BTNode *bt) {
	if(bt) {
		printf("%d\n", bt->data);
		preOrderTraverse(bt->left);
		preOrderTraverse(bt->right);
	} else {
		return;
	}
}

void nonRecursivePreOrderTraverse(BTNode *bt) {
	Stack s = createStack(20);
	
	while(bt || !isStackEmpty(s)) {
		while(bt) {
			printf("%d", bt->data);
			push(&s, *bt);
			bt = bt->left;
		}
		if(!isStackEmpty(s)) {
			BTNode t = pop(&s);
			bt = t.right;
		}
	}
} 

int main() {
	BTNode bt;
	bt.data = 5;
	bt.left = NULL;
	bt.right = NULL;
	addElement(&bt, 2);
	addElement(&bt, 6);
	nonRecursivePreOrderTraverse(&bt);
}
