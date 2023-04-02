# Spring

## 1 浅谈 Bean 和 IoC 容器

Bean 通常用于描述系统中的组件、实体或服务，它们是一种可重用的、可移植的组件，可以在不同的应用程序和框架中使用。Bean 通常具有一定的业务逻辑，可以执行某些特定的任务或操作。

Mybatis 的 SqlSession 是一个常用的对象，SqlSession是一个轻量级的非线程安全对象，用于在Java应用程序中与数据库交互。SqlSession 通常是在一个业务方法中创建、使用和关闭。而创建 SqlSession 时，一般使用 SqlSessionFactory 工厂类来创建，它是线程安全的对象。

如果想对数据库进行 CRUD 操作，就一定会在 Service 出现由 SqlSessionFactory 创建 SqlSession 这一过程。这是一个可复用的过程。

如果每次在获取 SqlSession 时都可以自动使用 SqlSessionFactory 的方式来获得，那么开发者就可以更专注于业务逻辑的编写了。

那么将 SqlSessionFactory、SqlSession 这两个对象交给 Spring 来管理，在 Spring 的配置中定义这两个对象的依赖关系，让 Spring 来完成 SqlSession 繁琐的获取过程，就是控制反转（ IoC ），SqlSessionFactory 和 SqlSession 就是两个 Bean，负责管理 Bean 的东西就叫做（ IoC 容器）。

> 该`org.springframework.context.ApplicationContext`接口表示 Spring IoC 容器，负责实例化、配置和组装 bean。**容器通过读取配置元数据获取有关要实例化、配置和组装哪些对象的指令。**配置元数据以 XML、Java 注释或 Java 代码表示。它允许您表达组成应用程序的对象以及这些对象之间丰富的相互依赖关系。
>
> 原文链接：https://docs.spring.io/spring-framework/docs/current/reference/html/core.html#beans-introduction
>
> 下文其他引用无另说明时均为此链接，后不赘述。

### 1. 1  Bean 的注意事项

1. Bean 命名约定：

   约定是在命名 bean 时使用标准 Java 约定作为实例字段名称。也就是说，bean 名称以小写字母开头，并从那里开始使用驼峰式大小写。此类名称的示例包括`accountManager`、 `accountService`、`userDao`、`loginController`等。

2. 创建 Bean 别名：

   ```xml
   <alias name=".." alias="..">
   ```

## 2 配置元数据

### 2. 1  XML 方式配置

> ```xml
> <?xml version="1.0" encoding="UTF-8"?>
> <beans xmlns="http://www.springframework.org/schema/beans"
>     xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
>     xsi:schemaLocation="http://www.springframework.org/schema/beans
>         https://www.springframework.org/schema/beans/spring-beans.xsd">
> 
>     <bean id="..." class="..."> (1) (2)
>         <!-- collaborators and configuration for this bean go here -->
>     </bean>
> 
>     <bean id="..." class="...">
>         <!-- collaborators and configuration for this bean go here -->
>     </bean>
> 
>     <!-- more bean definitions go here -->
> 
> </beans>
> ```
>
> （1） 该`id`属性是一个字符串，用于标识单个 bean 定义。
> 
> （2） 该`class`属性定义 bean 的类型并使用完全限定的类名。 

有时候需要将一些元数据配置的作用域跨域多个配置文件：

```xml
<beans>
    <import resource="daos.xml"/>
    <import resource="services.xml"/>

    <bean id="..." class="..."/>
    <bean id="..." class="..."/>
</beans>
```

## 3 实例化和使用容器

```java
ApplicationContext context = new ClassPathXmlApplicationContext("daos.xml");
UserMapper mapper = context.getBean("userMapper", UserMapper.class);
List<User> userList = mapper.selectUsers();
for(User t : userList) {
	..
}
```

`ClassPathApplicationContext()` 参数为读取元数据的配置文件。

`getBean()` 即读取元数据中配置好的 Bean，容器会实例化这个 Bean，可以调用该 Bean 所拥有的方法。

## 4 构造 Bean

### 4. 0 依赖注入（ Dependency Injection - DI ）

如果按实际需求来举例，Service 层在完成业务逻辑的过程中一定会调用来自 DAO 层的服务；而为了调用 DAO 层的服务，就需要引入 DAO 层的上下文对象，这就使 Service 层的职责不单一，耦合度增加。

为解决这个问题，一般将 DAO 层上下文作为一个属性放到 Bean 中，由 IoC 容器来完成该 Service 对下层依赖的注入。

### 4. 1 构造方法依赖注入

构造方法对 Bean 进行依赖注入一般有以下三种方式：

1. 按参数类型依赖注入：

   ```xml
   <bean id=".." class="..">
       <constructor-arg type="int" value="19"/>
       <constructor-arg type="java.lang.String" value="iamqwq"/>
   </bean>
   ```

   如果类型是 Java 中的原子类型，则可以直接在 type 后使用；如果类型是一个类，则需要写完全限定名。

   而且，很明显，如果在构造器中有重复的类型参数，这种方法是不可用的。（即使可用也不推荐使用，因为按类型构造可读性较低，容易引起歧义）

2. 按参数下标依赖注入：

   ```xml
   <bean id=".." class="..">
       <constructor-arg index="0" value="19"/>
       <constructor-arg index="1" value="iamqwq"/>
   </bean>
   ```

   这种方式较第一种可行性略高，但因为按参数下标来构造仍存在歧义性（例如方法在后续更新时将参数位置交换了），所以最好当构造方法有且仅有一个参数时使用这种方法进行依赖注入。

3. 按参数名称依赖注入：

   ```xml
   <bean id=".." class="..">
       <constructor-arg name="age" value="19"/>
       <constructor-arg name="name" value="iamqwq"/>
   </bean>
   ```

   此处应注意的是，
   > Java编译器在编译Java源代码时，会将方法参数名编译成与原本不相同的参数名，这个过程称为“变量重命名”（Variable Renaming）。这是为了防止变量名冲突，因为不同的方法可能会有相同的参数名，如果它们在编译后的字节码中使用相同的参数名，会导致命名冲突。为了避免这种情况，编译器会将方法参数名编译成一个唯一的名称，例如arg0、arg1、arg2等等，以确保每个参数都有一个唯一的标识符。这样，即使不同的方法具有相同的参数名，它们在编译后的字节码中使用的参数名也会不同，不会出现命名冲突的问题。

   
   
   因此，如果要使用这种方式进行依赖注入，需要在类中的构造方法上添加 JDK 注解 `@ConstructorProperties` ，它用于标记构造函数的参数名称，以便在使用反射创建对象时，能够根据参数名称来匹配参数值。

### 4. 2 基于 Setter 的依赖注入

// TODO

循环依赖？？实际可能出现循环依赖的场景？？

参数编程验证？？

#### 4. 2. 0 基于 Setter 的依赖注入的本质

Spring 在进行基于 Setter 的对属性名称注入的时候，不会产生运行时变量重命名所导致的错误吗？

实质上 Spring 是通过反射的机制获取到 Bean 的 Setter 方法来将依赖注入到 Bean 中的，因此不论运行时属性被重命名为什么，Setter 的参数也始终能找到对应的属性（因为方法参数唯一）。

#### 4. 2. 1  Setter 方式原子属性的依赖注入

```xml
<bean id="person" class="../Person.class">
    <property name="age" value="19"/>
</bean>
```

#### 4. 2. 1  Setter 方式引用属性的依赖注入

```xml
<bean id="iamqwqSchool" class="../School.class">
    <property name="address" value="xx省市xx路xx号"/>
    ..
</bean>
<bean id="person" class="../Person.class">
    <property name="school" ref="iamqwqSchool"/>
</bean>
```

但 iamqwqSchool 这个 Bean 中的 address 似乎是一个 String 类型，众所周知，String 类型并不是 Java 中的原子类型，为什么可以使用 value 来注入？

> `value`元素的属性将`<property/>`属性或构造函数参数指定为人类可读的字符串表示形式。Spring 的 [转换服务](https://docs.spring.io/spring-framework/docs/current/reference/html/core.html#core-convert-ConversionService-API)用于将这些值转换 String 为属性或参数的实际类型。

因此，可以不用担心过于复杂的 String 为引用类型的问题。

