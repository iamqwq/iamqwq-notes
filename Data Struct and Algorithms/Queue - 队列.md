# Queue - 队列

队列也是一种操作受限的线性表。放在现实中很常见：队列是先排队的人先进行操作。在计算机中，队列同样常见：如果有一系列的操作任务需要按顺序执行，则会将任务存入队列进行排队，逐次执行。队列是一种先入先出的数据结构，同样是限制只能在结构尾部。

需要注意的是一个线性的队列结构会出现假溢出的情况，一般使用循环队列。

## 1 队列的顺序存储结构

```c
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
```

## 2 队列的链式存储结构

