# Annotation - 注解

注解由于可以被反射获取内容的特性，常被用作简化代码的工具，因此在框架中随处可见。

## 内置注解

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

## 元注解

元，英文中对应 meta，也就是 .. 之前的，或理解为最开始的意思。元注解，即为标注注解的注解。

1. `@Retention` 注解用于标识注解的存活期，它共有三种可能的取值：
   - `RetentionPolicy.SOURCE` 该值表示注解仅在源码阶段有效，在编译器编译时即会将其丢弃。
   - `RetentionPolicy.CLASS` 该值表示注解仅在编译阶段及其之前有效，不会被加载到 JVM 中解释执行。
   - `RetentionPolicy.RUNTIME` 该值表示注解将会在运行时有效，这也也意味着反射可以获取到注解。
2. `@Documented` // TODO
3. `@Target` 注解用于标识注解的作用域，该注解的取值基本上见名知意，因此仅提供其取值枚举类的位置：`java.lang.annotation.ElementType`



```java




@Target

@Inherited
```

