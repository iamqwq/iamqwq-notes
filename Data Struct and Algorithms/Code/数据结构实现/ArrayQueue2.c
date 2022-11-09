#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int *head;
	int front;
	int rear;
	int size;
} Queue;

Queue createQueue(int size) {
	Queue q;
	q.head = (int *)malloc((size + 1) * sizeof(int));
	q.size = size;
	q.rear = 0;
	q.front = 0;
	return q;
}

int isQueueEmpty(Queue q) {
	if(q.front == q.rear) {
		return 1;
	} else {
		return 0;
	}
}

int isQueueFull(Queue q) {
	if((q.rear + 1) % (q.size + 1) == q.front) {
		return 1;
	} else {
		return 0;
	}
}

void addElement(Queue *q, int data) {
	if(!isQueueFull(*q)) {
		q->rear = (q->rear + 1) % (q->size + 1);
		*(q->head + q->rear) = data;
	} else {
		printf("qwq");
	}
}

int deleteElement(Queue *q) {
	if(!isQueueEmpty(*q)) {
		q->front = (q->front + 1) % (q->size + 1);
		return *(q->head + q->front);
	} else {
		printf("qwq");
	}
}

int main() {
	int i;
	Queue q = createQueue(5);
	addElement(&q, 10);
	addElement(&q, 11);
	addElement(&q, 12);
	addElement(&q, 13);
	addElement(&q, 14);
	for(i = 0; i < 5; i++) {
		printf("%d ", deleteElement(&q));
	}
	addElement(&q, 20);
	printf("%d", deleteElement(&q));
}
