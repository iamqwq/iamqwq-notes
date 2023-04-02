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

> ```java
> ApplicationContext context = new ClassPathXmlApplicationContext("services.xml", "daos.xml");
> ```
>
> `ClassPathApplicationContext()` 参数为读取元数据的配置文件。（默认读取的路径根为 resource 文件夹）