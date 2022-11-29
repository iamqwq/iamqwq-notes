#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
	int data;
	struct BTNode *left;
	struct BTNode *right;
} BTNode;

BTNode* find(BTNode *bt, int data) {
	BTNode *t = bt;
	if(data == t->data || t == NULL) {
		return t;
	} else {
		if(data <= bt->data) {
			t = find(t->left, data);
		}
		if(data > bt->data) {
			t = find(t->right, data);
		}
		return t;
	}
}

BTNode* findMin(BTNode *bt) {
	BTNode *t = bt;
	while(t->left) {
		t = t->left;
	}
	return t;
}

BTNode* findMax(BTNode *bt) {
	BTNode *t = bt;
	while(t->right) {
		t = t->right;
	}
	return t;
}

BTNode* addElement(BTNode *bt, int data) {
	if(bt == NULL) {
		bt = (BTNode *)malloc(sizeof(BTNode));
		bt->left = NULL;
		bt->right = NULL;
		bt->data = data;
	} else if(data <= bt->data) {
		bt->left = addElement(bt->left, data);
	} else if(data > bt->data) {
		bt->right = addElement(bt->right, data);
	}
	return bt;
}

BTNode* deleteElement(BTNode *bt, int data) {
	BTNode *t;
	if(!bt) {
		return NULL;
	} else if(data < bt->data) {
		bt->left = deleteElement(bt->left, data);
	} else if(data > bt->data) {
		bt->right = deleteElement(bt->right, data);
	} else {
		if(bt->left && bt->right) {
			t = findMin(bt->right);
			bt->data = t->data;
			bt->right = deleteElement(bt->right, bt->data);
		} else {
			t = bt;
			if(!bt->left) {
				bt = bt->right;
			} else if(!bt->right) {
				bt = bt->left;
			}
			free(t);
		}
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

typedef struct Queue {
	int front;
	int rear;
	int size;
	BTNode *head;
} Queue;

Queue createQueue(int size) {
	Queue q;
	q.head = (BTNode *)malloc((size + 1) * sizeof(BTNode));
	q.front = 0;
	q.rear = 0;
	q.size = size;
	return q;
}

int isQueueEmpty(Queue q) {
	if(q.front == q.rear) {
		return 1;
	} else {
		return 0;
	}
}

void addElementQ(Queue *q, BTNode data) {
	if((q->rear + 1) % q->size != q->front) {
		q->head[++q->rear % q->size] = data;
	}
}

BTNode deleteElementQ(Queue *q) {
	if(!isQueueEmpty(*q)) {
		return q->head[++q->front % q->size];
	}
}

void preOrderTraverse(BTNode *bt) {
	Stack s = createStack(20);
	BTNode *t = bt;
	
	while(t || !isStackEmpty(s)) {
		if(t) {
			push(&s, *t);
			printf("%d\n", t->data);	
			t = t->left;
		} else {
			t = pop(&s).right;
		}
	}
}

void levelOrderTraverse(BTNode *bt) {
	Queue q = createQueue(20);
	BTNode *t = bt;
	addElementQ(&q, *t);
	while(!isQueueEmpty(q)) {
		BTNode tt = deleteElementQ(&q);
		printf("%d ", tt.data);
		t = &tt;
		if(t->left) {
			addElementQ(&q, *(t->left));
		}
		if(t->right){
			addElementQ(&q, *(t->right));
		}
	}
}

int main() {
	BTNode bt;
	bt.data = 5;
	bt.left = NULL;
	bt.right = NULL;
	addElement(&bt, 2);
	addElement(&bt, 7);
	addElement(&bt, 3);
	addElement(&bt, 1);
	addElement(&bt, 6);
	addElement(&bt, 8);
	/*
				5
			2		7
		  1   3   6   8
	*/
	deleteElement(&bt, 7);
	levelOrderTraverse(&bt);
	BTNode *t;
	t = find(&bt, 2);
	printf("\n%d\n%d", t ? t->data: -1, findMax(&bt)->data);
}
