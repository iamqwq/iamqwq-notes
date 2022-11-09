#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node, LinkedList;

LinkedList createLinkedList() {
	Node n;
	n.next = NULL;
	return n;
}

int getElement(LinkedList l, int i) {
	Node p;
	int j = 0;
	while(l.next != NULL && j <= i) {
		l = *(l.next);
		j++;
	}
	return l.data;
}

void addElement(LinkedList *l, int data) {
	Node *p;
	p = l;
	while(p->next != NULL) {
		p = p->next;
	}
	p->next = (LinkedList *)malloc(sizeof(LinkedList));
	p = p->next;
	p->data = data;
	p->next = NULL;
}

void insertElement(LinkedList *l, int i, int data) {
	Node *p = l;
	Node *t;
	int j = 0;
	while(l->next != NULL && j < i) {
		p = p->next;
		j++;
	}
	if(j == 0) {
		exit(0);
	}
	t = p->next;
	p->next = (Node *)malloc(sizeof(Node));
	p = p->next;
	p->data = data;
	p->next = t;
} 

int main() {
	LinkedList l = createLinkedList();
	addElement(&l, 1);
	addElement(&l, 2);
	addElement(&l, 3);
	insertElement(&l, 2, 100);
	for(int i = 0; i < 4; i++) {
		printf("%d ", getElement(l, i));
	}
}
