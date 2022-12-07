# Function - 函数

## 1 浅谈函数

函数在对象一节中提到过，它也是一种对象。因此在 JS 中的函数也有很多和传统函数不同的地方，例如函数可以当作字面量存储在变量中；又例如函数可以当作参数使用等。

## 2 函数的创建方式

### 2. 1 函数定义（函数声明 / 函数语句）方式

这种方式与传统的函数定义方式无异。

```javascript
function doSth() {
    console.log("doSth.");
}
```

### 2. 2 函数表达式方式 以及匿名函数

这种方式将函数当作字面量存储到变量中，这么做的目的多是为了将它当作变量传入某一函数中。

```javascript
const displayName = function(name) {
    console.log(name);
}
```

另外函数并没有定义名称，这种写法是匿名的。

### 2. 3 箭头函数方式

箭头函数的出现是为了解决两种问题的：

1. 为了让函数更简洁。
2. 解决 this 的语义混乱问题。

首先先从简洁的角度来考察箭头函数的使用：

```javascript
var fun = (a, b) => a + b;
```

这点显然是毋庸置疑的。上述写法的含义是，对于参数 a, b 返回 a + b 的值，在参数只有一个的时候括号可以省略，返回前的语句可以使用 { } 包裹住书写。

再从 this 语义混乱的角度来看。首先我们该知道在构造函数（对象原型）中会使用 this 来表示自身对象，例如：

```javascript
var brieflyIntroduce = function() {
    console.log("i am " + this.name);
}

function Person(name, age, sex, introduce) {
    this.name = name;
    this.age = age;
    this.sex = sex;
    this.introduce = introduce;
}

var iamqwq = new Person("iamqwq", 18, "male", brieflyIntroduce);

iamqwq.introduce(); // result: i am iamqwq.
```

但在函数中嵌套定义函数并尝试查看 this 指示的是什么时：

```javascript
var brieflyIntroduce = function() {
    function hello() {
        console.log(this.name + "says: ");
    }
    hello();
    console.log("i am " + this.name);
}

var iamqwq = new Person("iamqwq", 18, "male", brieflyIntroduce);

iamqwq.introduce(); // result: says: i am iamqwq.
```

this.name 没有按照想象的那样输出。转而尝试直接输出 this 之后的结果却是令人匪夷所思的 Window。

在全局状态下的 this 指向全局对象（浏览器端指向 window ），函数中的 this 指向最近调用函数的对象，函数前没有对象则视为全局对象调用的函数。

箭头函数则会继承外部函数，指向创建时外部函数的 this 值。

## 3 回调

回调即是作为函数参数的函数，传给其它函数由其负责调用。例如数组的 map 方法（创建一个新数组，这个新数组由原数组中的每个元素都调用一次提供的函数后的返回值组成）：

> const array1 = [1, 4, 9, 16];
>
> // pass a function to map
> const map1 = array1.map(x => x * 2);
>
> console.log(map1);
> // expected output: Array [2, 8, 18, 32]

