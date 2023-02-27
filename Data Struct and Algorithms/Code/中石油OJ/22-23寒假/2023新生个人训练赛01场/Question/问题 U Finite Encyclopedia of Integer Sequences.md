#### 题目描述

In Finite Encyclopedia of Integer Sequences (FEIS), all integer sequences of lengths between 1 and N (inclusive) consisting of integers between 1 and K (inclusive) are listed.
Let the total number of sequences listed in FEIS be X. Among those sequences, find the (X⁄2)-th (rounded up to the nearest integer) lexicographically smallest one.

Constraints
1≤N,K≤3×105
N and K are integers.

#### 输入

Input is given from Standard Input in the following format:
K N

#### 输出

Print the (X⁄2)-th (rounded up to the nearest integer) lexicographically smallest sequence listed in FEIS, with spaces in between, where X is the total number of sequences listed in FEIS.

#### 样例输入

```
3 2
```

#### 样例输出

```
2 1 
```

#### 提示

There are 12 sequences listed in FEIS: (1),(1,1),(1,2),(1,3),(2),(2,1),(2,2),(2,3),(3),(3,1),(3,2),(3,3). The (12⁄2=6)-th lexicographically smallest one among them is (2,1).