# Annotation - 注解

注解被大量用于框架开发，配合反射可以进行动态的修改类中的内容，简化代码、使代码更加灵活，因此在框架中随处可见。

## 1 使用原生注解

### 1. 1 内置注解

1. `@Override` 注解可以使用在方法上，它将会检查注解所在类的父类（或者引用的接口）是否存在该方法，如果没有则会报错。

   下面局最简单的例子（所有类都继承自 `java.lang.Object` 类）

```java
@Override
public int hashCode() {
    ...
}
```

2. `Deprecated` 注解可以用在绝大多数位置（构造器、字段、局部变量、方法、包、参数、类（接口与枚举也可以））上，它将会标记该位置为过时的，并在编译时警告
3. `@SuppressWarnings` 注解可以忽略注解中声明的警告。

## 2 定义注解

定义注解，势必需要修饰注解的类型和功用。这种修饰方法在常规的字段中是权限修饰符、类型等，在注解中则是元注解。

### 2. 1 元注解

元，英文中对应 meta，也就是 .. 之前的，或最开始的意思。元注解，即为标注注解的注解。（小插曲：形而上学又称 Meta - Physics）

1. `@Retention` 注解用于标识注解的存活期，它共有三种可能的取值：
   - `RetentionPolicy.SOURCE` 该值表示注解仅在源码阶段有效，在编译器编译时即会将其丢弃。
   - `RetentionPolicy.CLASS` 该值表示注解仅在编译阶段及其之前有效，不会被加载到 JVM 中解释执行。
   - `RetentionPolicy.RUNTIME` 该值表示注解将会在运行时有效，这也也意味着反射可以获取到注解。
2. `@Documented` // TODO
3. `@Target` 注解用于标识注解的作用域，该注解的取值基本上见名知意，因此仅提供其取值枚举类的位置：`java.lang.annotation.ElementType`
4. `@Inherited` 注解用于标识注解是否会让注解的类的子类也同样生效。

### 2. 2 定义语法

使用形似 `@interface` 的语法来定义注解，使用元注解修饰：

```java
@Target(ElementType.FIELD)
@Retention(RetentionPolicy.RUNTIME)
public @interface Range {

    int min() default 0;
    int max() default 255;

}
```

注解内的成员变量除了需要定义类型以外，还需要加括号，最好所有成员变量都标注默认值。而使用注解的地方则可以像这样向注解内的成员变量传值：

```java
@Range(max = 26)
public String name;
```

如果没有参数，则可以省略括号：

```java
@Range
public String name;
```



