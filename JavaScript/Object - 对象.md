# Object - 对象

本文假设读者已经对面向对象思想有一定的理解。

## 1 浅谈 JS 对象

与 Java 中的对象核心思想有些不同，首先 JS 中的函数、数组也同样是对象，其中函数是对象是较为重要的不同。另外，JS 中可以直接创建对象的实例而不创建类，这意味着不是所有的对象都是从抽象的类中实例化出来的。

从面向对象思想的角度出发，我自然的就强烈的想到要创造一个对象需要一个类，并试图在 JS 中找到传统的类 - 对象思想。但在 ES6 之前的版本标准中这是困难的，因为在那之前 JS 中并没有类的概念。

接下来就从面向对象的思想为出发点，按从 JS 标准时间顺序来讨论创造对象的方法。

## 2 构造对象

### 2. 1 对象原型（构造函数）构造对象

```javascript
function Person(name, age, sex) {
    this.name = name;
    this.age = age;
    this.sex = sex;
}

// Then you can use "new" to create an Person object.
var iamqwq = new Person("iamqwq", 18, "male");
```

这时可以将 Person 这种对象作为参数使用。

另一点有趣的是，无论何时，你都可以给对象新增属性而不去改变构造函数中的代码（但这并不影响其它对象），就像下面这样。

```javascript
iamqwq.height = 181;
// iamqwq now have property "height".
```

### 2. 2 直接构造对象

前文提到 JS 可以越过类直接构造对象，下例演示了创建一个不从任何类中实例化的对象。

```javascript
var iamqwq = {
    name: "iamqwq",
    age: 18,
    sex: "male",
};
```

这样 iamqwq 就被视作是一个对象。可以发现 JS 中的对象属性表现方式或许显得有些奇怪，有些像键值对，这是 JS 中特有的写法之一。

如果对象需要某种方法，则需要像这样写：

```javascript
var iamqwq = {
    . . . ,
    doSomething: function() {
        console.log("i am doing sth.");
    }
};
```

这显然是将函数当成了一种字面量，这正是将函数当作对象的一种体现。（此处的函数为匿名函数，详见后述的函数一节。）

### 2. 3 类构造对象

创建类的方式是简明的，类通过 class 关键字声明创建。在类的内容当中，这些可能会存在的东西无非是以下：

> ```javascript
> class MyClass {
>   // Constructor
>   constructor() {
>     // Constructor body
>   }
>   // Instance field
>   myField = "foo";
>   // Instance method
>   myMethod() {
>     // myMethod body
>   }
>   // Static field
>   static myStaticField = "bar";
>   // Static method
>   static myStaticMethod() {
>     // myStaticMethod body
>   }
>   // Static block
>   static {
>     // Static initialization code
>   }
>   // Fields, methods, static fields, and static methods all have
>   // "private" forms
>   #myPrivateField = "bar";
> }
> ```
>
> 原文链接：https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Using_Classes

这对于熟知面向对象思想的人来说正是再简单不过了，构造对象的方式依然是使用 new 关键字。

```javascript
var myObject = new MyClass;
```