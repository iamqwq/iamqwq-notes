# Enum - 枚举

枚举类通常用来表示一组常量，可以使用一个简单的例子来说明：

```java
public enum Size {
    SMALL, MEDIUM, LARGE;
}
```

> 实际上，这个声明定义的类型是一个类，它刚好有 3 个实例，不可能构造新的对象。

我们或许可以通过另一种看起来相似的方法来实现枚举的功能：

```java
public class Size {
    public static final int SMALL = 1;
    public static final int MEDIUM = 2;
    public static final int LARGE = 3;
}
```

而在使用的时候可以通过判断变量是否与 Size 中的值相同来进行下一步操作：

```java
if(size == SMALL) {
    . . .
}
```

但是这有一些问题：即无法知道 size 的值是否合法，并且定义的常量可以用作其它用途。而枚举类在这种情景下使用无疑是更合适的。

