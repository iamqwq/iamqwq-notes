# Array - 数组

数组是一种最基本的集合结构，它最大的作用就是将复数个元素按顺序的方式存储到连续空间中。

## 声明和初始化方式

如果我们需要声明整数数组：

```java
int[] numArr;
int numArr[];
```

上例两种写法均可，但 Java 中大多数人使用第一种风格。

> 因为它可以将类型 int[] （整型数组）与变量名清晰地分开。

如果我们需要将其初始化为大小为 5 的整数数组：

```java
int[] numArr = new int[5];
```

这种情况并没有为其定义值，这时所有元素都会被初始化为 0 （boolean 型则是 false，对象则是 null）。如果需要手动提供初始值，则我们可以采用下例这种写法：

```java
int[] numArr = { 1, 2, 3, 4, 5 };
```

最后一个元素之后允许加逗号（这会使添加元素变得方便）：

```java
int[] numArr = {
    1,
    2,
    3,
    4,
    5,
};
```

**值得注意的是，Java 中允许存在长度为 0 的数组。并且一旦数组大小确定下来，大小就不能再次改变了。**

但是我们可以定义一个匿名数组来重新初始化一个已有的数组变量：

```java
int[] numArr = {1, 2, 3, 4, 5};
numArr = new int[] {1, 2, 3, 4, 5, 6}; // Now numArr's size is 6
```

## 数组的访问方式

数组中的每一个值都称为一个元素。每个元素都有一个下标，下标从 0 开始，第一个元素的下标为 0 ，第二个元素的下标为 1，以此类推。使用 数组变量[下标] 的形式来引用。数组变量.length 可以获得数组中的元素个数。下例是通过 数组变量.length 和 访问元素的知识来遍历整个数组输出他们的值。

```java
for(int i = 0; i < numArr.length; i++) {
    System.out.println(numArr[i]);
}
```

> Java 中的 [] 运算符被预定义为会完成**越界检查**，而且没用指针运算，即不能通过 a 加 1得到数组中的下一个元素。

## 数组的相关操作

### 数组拷贝

Arrays 类中的 copyOf 方法。

```java
newArr = Arrays.copyOf(numArr, numArr.length);
```

copyOf 方法的第一个参数是要拷贝的数组变量，其第二个参数则是新数组的长度。上例将 numArr 完整的（因为第二个参数取的是 numArr 数组的长度）拷贝到了 newArr 中。

### 数组排序

Arrays 类中的 sort 方法。

```java
Arrays.sort(numArr);
```

> 这个方法使用了优化的快速排序（QuickSort）算法。快速排序算法对于大多数数据集合来说都是效率比较高的。

### for each 循环

for each 是循环的一种，可以在不引用下标的情况下遍历整个数组。

```java
for(int i : numArr) {
    System.out.println(i);
}
```

在这个 for 中的每次循环都会让 i 来替代 numArr 中的一个元素，直到遍历完成。

> 这个循环应该读作 “循环 a 中的每一个元素” （for each element in a）。

