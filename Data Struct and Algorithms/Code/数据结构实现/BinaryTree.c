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

void printElements(BTNode *bt) {
	if(bt != NULL) {
		printf("%d ", bt->data);
		printElements(bt->left);
		printElements(bt->right);
	}
}

int main() {
	BTNode bt;
	bt.data = 10;
	bt.left = NULL;
	bt.right = NULL;
	addElement(&bt, 1);
	addElement(&bt, 11);
	addElement(&bt, 6);
	printElements(&bt);
}
