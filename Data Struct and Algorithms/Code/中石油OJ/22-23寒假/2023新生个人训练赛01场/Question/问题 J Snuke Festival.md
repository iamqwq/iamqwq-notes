### 问题 J: Snuke Festival

#### 题目描述

The season for Snuke Festival has come again this year. First of all, Ringo will perform a ritual to summon Snuke. For the ritual, he needs an altar, which consists of three parts, one in each of the three categories: upper, middle and lower.
He has N parts for each of the three categories. The size of the i-th upper part is Ai, the size of the i-th middle part is Bi, and the size of the i-th lower part is Ci.
To build an altar, the size of the middle part must be strictly greater than that of the upper part, and the size of the lower part must be strictly greater than that of the middle part. On the other hand, any three parts that satisfy these conditions can be combined to form an altar.
How many different altars can Ringo build? Here, two altars are considered different when at least one of the three parts used is different.

Constraints
1≤N≤105
1≤Ai≤109(1≤i≤N)
1≤Bi≤109(1≤i≤N)
1≤Ci≤109(1≤i≤N)
All input values are integers.

#### 输入

Input is given from Standard Input in the following format:
N
A1 … AN
B1 … BN
C1 … CN

#### 输出

Print the number of different altars that Ringo can build.

#### 样例输入

```
2
1 5
2 4
3 6
```

#### 样例输出

```
3
```

#### 提示

The following three altars can be built:
Upper: 1-st part, Middle: 1-st part, Lower: 1-st part
Upper: 1-st part, Middle: 1-st part, Lower: 2-nd part
Upper: 1-st part, Middle: 2-nd part, Lower: 2-nd part