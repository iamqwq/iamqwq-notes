# Tree - 树

树的应用场景可以分为两种情况来讨论：

1. 当需要表示有层次的数据时，很明显，线性结构是无力的。表示有层次的数据，树是有绝对竞争力的。例如计算机的文件系统，又或是浏览器的 DOM 树。

2. 当需要设计需要频繁查找数据，也需要频繁插入数据的结构时，无论使用数组，还是使用链表，都有不足（要么是增删速度慢，要么是查找速度慢）。从这个角度来看，一些树（如二叉树）则可以理解为数组和链表的一个折中，一些树可以同时将查找和增删的时间成本同时做到合适。

   > 再者，树有个好处，就是当节点有序的时候（即有序树），那么在这个树上搜索一个节点是很快的（log级别），所以，现在的索引一般都是用各种树（数据库如mysql使用B+树）。
   >
   > 取自知乎用户 @dccmx [这个回答](https://www.zhihu.com/question/20176446)

在此主要讨论的是第二种场景的树。在这种场景中的树中有一个很具代表性的结构，即为二叉树。二叉树的种类及其变种繁多不易梳理，因此首先从二叉树的基本概念开始，然后从二叉树节点的实现略过整树的构造直接整理二叉树的遍历。

## 0 二叉树的基本概念

在认识二叉树前，首先需要认识普通的树：

<img src="Tree - 树.assets/202211031602tree-3x.excalidraw.png" alt="202211031602tree-3x.excalidraw" style="zoom: 50%;" />

子节点、父节点、根节点：树的构成从一个单一无父节点的根节点开始，然后向下有多个子节点。

层次、深度、度、叶子结点：深度是树的最大层次数，根节点的层次为 1 ，以此类推。度则是节点拥有的子树数量，度为 0 的节点为叶子节点。

路径、祖先、兄弟：节点数量为 n 的树，将节点们相连的路径必有 n + 1 条。从根节点到 A 节点的路径上的所有节点都为 A 节点的祖先，而节点同层次但不同父节点的节点称为兄弟。

二叉树是树的一种，这种树每个节点最多只有两个子树。

抽象数据类型的构建思路：

```c
typedef struct BTNode {
	int data;
	struct BTNode *left;
	struct BTNode *right;
} BTNode;
```

## 1 二叉树遍历

先序中序和后序的递归遍历仅在于输出的位置不同，思路大体一致。

我注意到，树的遍历的思想主要依靠对递归和堆栈的理解，而递归又和堆栈紧密相关，因此堆栈作为树的前提知识的重要性不言而喻。

### 1. 1 先序遍历

```c
void preOrderTraverse(BTNode *bt) { // "BTNode" means binary tree node.
	if(bt) {
		printf("%d ", bt->data); // Assume that the type of the data is Integer.
		printElements(bt->left);
		printElements(bt->right);
	}
}
```

### 1. 2 中序遍历

```c
void inOrderTraverse(BTNode *bt) {
	if(bt) {
		printElements(bt->left);
		printf("%d ", bt->data);
		printElements(bt->right);
	}
}	
```

### 1. 3 后续遍历

```c
void postOrderTraverse(BTNode *bt) {
	if(bt) {
		printElements(bt->left);
		printElements(bt->right);
		printf("%d ", bt->data);
	}
}
```

### 1. 4 先序非递归遍历

因为递归使用了堆栈的存储结构，所以我们也可以使用堆栈来进行非递归的遍历。思路是遇到节点时如果左子节点不为空就将节点入栈并输出，如果为节点不存在，则让当前节点更新为堆栈中保存的父节点的右子节点，然后用相同的方法遍历右子节点。

（下例代码基于一个存储类型为二叉树节点的堆栈的抽象数据类型）

```c
void preOrderTraverse(BTNode *bt) {
	Stack s = createStack(20);
	BTNode *t = bt;
	while(t || !isStackEmpty(s)) {
		if(t) {
			push(&s, *t);
			printf("%d ", t->data);	
			t = t->left;
		} else {
			t = pop(&s).right;
		}
	}
}
```

### 1. 5 广度优先（层序）遍历

```c
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
```

## 2 构造 / 组织树（树的种类）

### 2. 1 二叉查找树

 二叉树的形态决定了二分的思想适用于二叉树，因此构建一个可供查找的树是可能的，而且二分查找算法的时间复杂度为 O(log2n) ，这无疑是较快的。

备忘：操作：find	findMin	findMax	insert	delete

二叉查找树的构造方式是以一个数据为基准，将该数据作为根节点，比根节点数据小的放入左子树，比根节点数据大的放入右子树。若左 / 右子树已经存在节点，则再次进行同样的比较（比该节点数据小的放入左子树，大的放入右子树）直到自身成为叶子节点为止。

添加节点的方式是构造树的核心，为理解二叉查找树首先尝试编写添加节点函数是良好的方法。

#### 2. 1. 1 查找节点

查找节点的本质是根据提供的节点的数据，返回该节点所在的地址。

```c
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
```

#### 2. 1. 2 添加节点

要注意的是该函数没有考虑为根节点补充数据的情况。

```c
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
```

#### 2. 1. 3 删除节点

删除节点时有三种情况：

1. 删除的节点为叶节点。

   删除这样的节点思路是简明的，把父节点的左 / 右子节点指针设空即可。

2. 删除的节点为有一个子树的节点。

   这种情况可以将删除节点的父节点的左 / 右子节点指针改为子节点的地址。

3. 删除的节点为有左右子树的节点。

   这种情况应该使用一种化繁为简的思想，即是把它转化为第二种情况。

   具体来说是使用另一节点替代被删除节点，但如何替代才可以让二叉查找树保持其结构？又如何将其简化为第二种情况？

   这里有一个精妙的解法：就是使左子树的最大元素或右子树的最小元素替代删除的节点。也就是说，真正进行删除操作的是左子树的最大元素的节点或右子树的最小元素的节点，而我们想要删除的节点实质只是在其父节点的子节点指针被替换了而已，并不需要对其子树做操作。

   它首先满足使二叉查找树保持其结构的条件：因为左子树的最大元素恒小于右子树任何元素，右子树最小元素恒大于左子树任何元素。

   又满足简化为第二种情况的条件（仅有一个子树）：左子树的最大元素节点不可能拥有右子树，因此其只可能有左子树；同样的，右子树的最小元素节点不可能拥有左子树，因此其只可能有右子树。

```c
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
```







