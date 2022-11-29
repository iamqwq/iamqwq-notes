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
	q.head = (int *)malloc(size + 1 * sizeof(int));
	q.front = 0;
	q.rear = 0;
	q.size = size;
	return q;
}

// size = 6  front = 5  rear = 1
void addElement(Queue *q, int data) {
	if((q->rear + 1) % (q->size + 1) == q->front) {
		printf("Queue Full");
		return;
	}
	q->rear = (q->rear + 1) % (q->size + 1);
	*(q->head + q->rear) = data;
}

int deleteElement(Queue *q) {
	if(q->rear == q->front) {
		printf("Queue Empty");
		return 0;
	} else {
		q->front = (q->front + 1) % (q->size + 1);
	}
	return *(q->head + q->front);
}



int main() {
	Queue q = createQueue(4);
	addElement(&q, 1);
	printf("%d ", deleteElement(&q));
	addElement(&q, 2);
	addElement(&q, 3);
	addElement(&q, 4);
	addElement(&q, 1);
	addElement(&q, 1);
	printf("%d ", deleteElement(&q));
	printf("%d ", deleteElement(&q));
	printf("%d ", deleteElement(&q));
	printf("%d ", deleteElement(&q));
} 
