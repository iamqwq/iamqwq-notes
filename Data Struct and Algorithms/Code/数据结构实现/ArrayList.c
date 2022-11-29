#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList {
	int *head;
	int length;
	int size;
	int growthScale;
} ArrayList;

ArrayList createArrayList(int size) {
	ArrayList l;
	l.head = (int *)malloc(size * sizeof(ArrayList));
	l.size = size;
	l.length = 0;
	l.growthScale = 1;
	return l;
}

int getElement(ArrayList l, int i) {
	if(i > l.length) {
		exit(0);
	}
	return *(l.head + i);
}

void setElement(ArrayList *l, int i, int data) {
	if(i < l->length) {
		*(l->head + i) = data;
	} else {
		exit(0);
	}
}

void addElement(ArrayList *l, int data) {
	if(l->length >= l->size) {
		l = (ArrayList *)realloc(l, l->size + l->growthScale);
	}
	*(l->head + l->length) = data;
	l->length++;
}

void insertElement(ArrayList *l, int i, int data) {
	int j;
	if(l->length >= l->size) {
		l = (ArrayList *)realloc(l, l->size + l->growthScale);
	}
	for(j = l->length; j >= i; j--) {
		*(l->head + j + 1) = *(l->head + j);
	}
	l->length++;
	*(l->head + i) = data;
} 

int main() {
	ArrayList l = createArrayList(10);
	addElement(&l, 1);
	addElement(&l, 2);
	addElement(&l, 3);
	insertElement(&l, 2, 10);
	for(int i = 0; i < l.length; i++) {
		printf("%d ", getElement(l, i));
	}
	printf("\nlength: %d", l.length);	
}
