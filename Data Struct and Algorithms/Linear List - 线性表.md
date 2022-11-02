# Linear List - 线性表

> 线性表（ List ）：零个或多个数据元素的有限序列。

**有限序列**即是在说元素有限，但更重要的是元素之间存在顺序。

## 1 线性表的顺序存储结构

顺序结构指的是在内存中用一段连续的地址来存储数据的结构。

这种结构的优势在于可以根据元素下标快速计算每个元素的地址，也就是查找元素的速度很快。但缺点在于每次插入或移除元素则需要把后续所有的元素进行移动，即增删慢。

```c
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

// This function means add a new element to the last position.
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

// And the deleteElement function hasnt written yet.
```



## 2 线性表的链式存储结构

链式结构意味着每个元素都指明了下一个元素的位置，实现这种结构的方式是一个元素分为两个部分：其一是数据域，用来存储数据；其二是指针域。

很显然，增减元素比大规模的元素移动简单多了。但链式的结构同时也会让进行查找元素的操作不得不首先访问其前面的所有元素。稍作总结：增删快，查找慢。

```c
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
```
