# Generics - 泛型

## 1 构造泛型类对象

泛型程序设计让类或方法的操作可以复用到各种类型，不必为每个需要的类型都定义一个类或方法。

如果不使用泛型来实现存储各种元素的集合的功能，那么我们或许会想到指示存储 Object 类型来完成这一目的。但是这么做的坏处是我们不知道何时在这个集合中混入了其它类的对象元素，报错也往往不会出现在真正发生错误的位置。但是泛型可以避免这一问题，以 ArrayList 的使用为例：

```java
ArrayList<String> strings = new ArrayList<>();
ArrayList<Integer> nums = new ArrayList<>();
```

strings 是 ArrayList 的一个对象，存储的元素都为 String 对象；nums 同样是 ArrayList 的一个对象，不过存储的元素都为 Integer 对象。对于不同类的对象存储，都使用了 ArrayList 类来构造对象，如果试图在 strings 中添加数字元素则编译器会指出一个错误：

```console
'add(java.lang.String)' in 'java.util.ArrayList' cannot be applied to '(java.lang.Integer)'
```

ArrayList 可以为各种指定类对象元素提供存储，并检查传入的参数是否为指定的类型。

构造泛型类对象的语法如下例：

```java
// both is ok
ArrayList<String> strings1 = new ArrayList<String>();
ArrayList<String> strings2 = new ArrayList<>();
```

## 2 定义泛型类

以 ArrayList 为例，现在可以知道它是一个泛型类（. . . 为省略，此处仅展示了该类中的一部分）：

```java
public class ArrayList<E> extends . . . implements . . . {
    . . .
	private void add(E e, Object[] elementData, int s) {
        if (s == elementData.length) {
                elementData = this.grow();
        }

        elementData[s] = e;
        this.size = s + 1;
    }
    . . .
    public boolean add(E e) {
        ++this.modCount;
        this.add(e, this.elementData, this.size);
        return true;
    }
    . . .
}
```

可以注意到，ArrayList 的类名后有一个 `<E>`，当使用 public 的 add 方法时，会将一个 E 类型的参数 e 传入（暂且不管其余参数）private 的 add 方法。

这个 E 即是泛型类中引入的类型变量，用尖括号包裹置于类名之后（可以有多个类型变量）。类型变量也是一个变量，回想起来，在上节使用 `ArrayList<String> strings = new ArrayList<>();` 时传入了这个变量，将这个泛型类的类型变量设为了 String，因此，在调用 add 方法时，E 就等同于 String。

除基础的定义泛型类之外，可以限定传入的类型变量必须实现某个接口：

```java
public class Sorter<T extends Comparable> {
    . . .
}
```

> 一个类型变量可以有多个限定，例如：
>
> T extends Comparable & Serializable
>
> 限定类型用 " & " 分隔，而逗号用来分隔类型变量。

## 3  定义泛型方法 TODO

