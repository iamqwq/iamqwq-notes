#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node, LinkedList;

LinkedList CreateLinkedList() {
	Node n;
	n.data = 0;
	n.next = NULL;
	return n;
}

void AddElement(LinkedList *l, int data) {
	++l->data;
	Node *p;
	p = l;
	while(p->next != NULL) {
		p = p->next;
	}
	p->next = (Node *)malloc(sizeof(Node));
	p = p->next;
	p->data = data;
	p->next = NULL;
}

int GetElement(LinkedList l, int i) {
	int j = 0;
	while(l.next != NULL && j <= i) {
		l = *(l.next);
		j++;
	}
	return l.data;
}

void ReverseLinkedList(LinkedList *l) {
	Node* head = l;
	if(head->data < 2) return;
	Node* pre = head->next;
	Node* curr = pre->next;
	Node* next = curr->next;
	pre->next = NULL;
	while(1) {
		curr->next = pre;
		pre = curr;
		curr = next;
		if(next) {
			next = next->next;
		}
		if(!curr) {
			break;
		}
	}
	head->next = pre;
}

int main() {
	
	// Create a LinkedList stuct.
	LinkedList l = CreateLinkedList();
	AddElement(&l, 1);
	AddElement(&l, 3);
	AddElement(&l, 5);
	AddElement(&l, 7);
	AddElement(&l, 9);
	
	// Show original LinkedList.
	int i;
	for(i = 0; i < l.data; ++i) {
		printf("%d ", GetElement(l, i));
	}
	printf("\n")
	
	// Show reversed LinkedList.
	ReverseLinkedList(&l);
	for(i = 0; i < l.data; ++i) {
		printf("%d ", GetElement(l, i));
	}
	
	return 0;
}

