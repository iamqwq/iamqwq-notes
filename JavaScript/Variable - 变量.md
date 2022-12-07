 

# Variable - 变量

JavaScript 是一种弱类型定义的语言，也就是说，我们在定义时不必过多关心变量的数据类型，而可以直接关注变量的其它方面的属性。

## 1 变量声明方式

从变量的作用域角度来看变量的类型，无非两类：全局作用域变量类型，以及局部（块）作用域变量类型。

### 1. 1 全局作用域变量类型

全局作用域的变量声明方式只有一种：即使用 var 关键字来声明变量。

```javascript
var num = 1.01;
var str = "hello?";
var bool = true;
```

### 1. 2 局部作用域变量类型

局部作用域的变量声明方式有两种：

1. let - 局部作用域的变量。

   ```javascript
   // Can't get i here.
   for(let i = 0; i < 10; i++) {
       console.log(i);
   }
   // Can't get i here.
   ```

2. const - 局部作用域的只读常量。

   具有和 let 一样的块作用范围，唯一不同的是其是只读的常量。

   ```javascript
   const PI = 3.1415926;
   ```

   但关于 const 有一件需要注意的事：

   当对象或数组被定义为常量时，并不能对其属性 / 元素起到只读的效果。

   > ```javascript
   > const MY_OBJECT = {"key": "value"};
   > MY_OBJECT.key = "otherValue"; // That's OK.
   > ```
   >
   > 原文链接：https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Grammar_and_Types

## 2 动态类型

首先指明一点，“ 动态类型 ” 指的是 JS 是动态类型语言，因此具有动态类型的性质。并非在 JS 中有一种类型名为动态类型。

动态类型（ Dynamically Typed ）和静态类型相对，这两者的差异在于类型检查时所处的阶段不同。静态类型的类型检查在编译阶段进行，而动态类型的类型检查在运行时进行。

这意味着静态类型语言在声明变量时同样要声明变量的类型，并且无法再把变量的类型进行转换。而动态类型语言则是根据赋值的内容进行转换。

因此，在 JS 中，下面的语法是合法的。

```javascript
let n = 11;
n = "kawaii";
```

## 3 数据类型

在 ECMAScript 标准当中定义了八种数据类型：

1. Number - 整数或浮点数。
2. BigInt - 较大的整数（可以超过数字的安全整数限制）。
3. String - 字符串。
4. Boolean - 布尔值。
5. Null - （实际是 null ）表示空。
6. Undefined - 表示为定义时的属性。
7. Symbol - 记号。
8. Object - 对象（包括函数和数组在内的特殊对象）。

这些数据存储形式并不复杂，因此详在后续介绍。

