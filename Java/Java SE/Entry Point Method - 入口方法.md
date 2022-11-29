# Entry Point Method - 入口方法

Java 的入口方法是一个最简单的可以执行的 Java 应用程序所使用的代码，下例是入口函数的格式（class 后的名称和代码块内的内容是可变的，其它部分则不是）。

（在 Intellij IDEA 中输入 psvm 等待半秒即可弹出代码补全框以补全 Java 入口方法，输入 sout 以补全 System.out.println(); ）

```java
public class Demo1EntryPointFunction {
    public static void main(String[] args) {
        System.out.println("hello world");
    }
}
```

它的输出结果是：

```java
hello world
```

> 这个程序虽然很简单，但所有的 Java 应用程序都具有这种结构，因此还是值得花一些时间来研究的。

在第一次学习的时候只能强行的去记忆入口方法的格式，现如今可以重新的对入口方法作一个解析。

## 解析 Java 入口方法

首先在入口函数外的是一个类，入口方法可以在任何类中。

```java
public class Demo1EntryPointFunction {
    
}
```

public 是一种访问修饰符，static 表示 main 方法是静态的，void 表示空返回值，String[] args 是可以传入的参数。

```java
public static void main(String[] args) {
        System.out.println("hello world");
}
```

还需要注意的是函数和方法的区别（此前在很多地方见到过称 Java 的入口点为函数的情况）：

> 程序的执行可以开始于命名点，要么是编程语言或操作系统定义的约定名字，要么是调用者指定的名字。在很多[C家族语言](https://zh.m.wikipedia.org/w/index.php?title=C家族编程语言列表&action=edit&redlink=1)中，这是叫做`main`的函数；作为结果，入口点经常叫做**主函数**。在[JVM语言](https://zh.m.wikipedia.org/w/index.php?title=JVM语言列表&action=edit&redlink=1)比如[Java](https://zh.m.wikipedia.org/wiki/Java)中，入口点是叫做`main`的静态方法；在[CLI语言](https://zh.m.wikipedia.org/w/index.php?title=CLI语言列表&action=edit&redlink=1)比如[C#](https://zh.m.wikipedia.org/wiki/C)中，入口点是叫做`Main`的静态方法[[1\]](https://zh.m.wikipedia.org/zh/入口点#cite_note-1)。

## 浅谈 Java 编码规范

最后观察它的格式（这是因为编码规范不会独立另写一篇文从而在这里浅谈一下）。

类名的命名一般为大驼峰风格 `ClassName` ，变量的命名则是小驼峰风格 `variableName` ，这两点经常能够见到。但是包名的命名风格则困扰我很久。最早的时候在阿里的 《 Java 开发手册 》找到了所有命名对应的规范（包名统一使用小写，点分隔符之间有且仅有一个自然语义的英语单词。包名统一使用单数形式，但是类名如果有复数含义，类名可以使用复数形式）。

代码的格式是一门艺术。代码格式如果规范则会提升可读性和美观性（或许还会有仪式感），规范类型有很多种，个人认为仅需保持代码风格统一即可。（[Java编码规范](https://github.com/wanfangdata/guide/blob/master/java%E5%BC%80%E5%8F%91%E8%A7%84%E8%8C%83/%E7%BC%96%E7%A0%81%E8%A7%84%E8%8C%83.md)）

括号风格主要有两种：

```java
public class ExampleClass {
    
}
```

```java
public class ExampleClass 
{
    
}
```

实际没有区别，但是个人倾向于使用前者。在线的学习资源一般使用前者，国内的科班教材示例一般采用后者。