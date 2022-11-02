# Servlet

## 1 浅谈 Servlet

> **Servlet**（Server Applet），全称**Java Servlet**。是用[Java](https://zh.wikipedia.org/wiki/Java)编写的[服务器](https://zh.wikipedia.org/wiki/服务器)端[程序](https://zh.wikipedia.org/wiki/程序)。其主要功能在于交互式地浏览和修改数据，生成动态[Web](https://zh.wikipedia.org/wiki/Web)内容。狭义的Servlet是指Java语言实现的一个[接口](https://zh.wikipedia.org/wiki/接口)，广义的Servlet是指任何实现了这个Servlet接口的[类](https://zh.wikipedia.org/wiki/类_(计算机科学))，一般情况下，人们将Servlet理解为后者。

在我目前看来，Servlet 最具有特点的地方是可以动态的生成 Web 内容，这是由它的运作原理决定的。当用户通过浏览器（或许是客户）端访问 Tomcat 的时候通常使用的 Get 或者 Post 方式，但是总归是一条请求。Web 容器此时会产生两个对象，即请求对象和响应对象。当这种请求第一次需要处理的时候，就会生成一个对应处理该类请求的 Servlet，而 Servlet 会通过 Service 方法获得请求对象和响应对象，然后 Servlet 根据请求来填充响应（这个部分即是开发者所需要做的），最终 Web 容器再将响应送回浏览器（或许是客户）端。

Web 容器、Web 服务器和应用服务器名词概念？ // TODO

![202210281715servlet-principle.excalidraw](C:\Users\iamqwq\Desktop\ImageTemp\Studing\202210281715servlet-principle.excalidraw.png)

## 2 通过 Maven 引入 Servlet

Oracle 将 Servlet 移交给 Eclipse 之后要求禁止使用 Java 商标，因此包名也从 javax.servlet 改成了 jakarta.servlet。

从 Maven 引入 Servlet，5.0.0 的引用是这样的：

```xml
<dependency>
        <groupId>jakarta.servlet</groupId>
        <artifactId>jakarta.servlet-api</artifactId>
        <version>5.0.0</version>
        <scope>provided</scope>
</dependency>
```

## 3  Using Servlet ~

首先在开始接触使用 Servlet API 前，先回顾一下编写 Servlet 的目的：

> 在我目前看来，Servlet 最具有特点的地方是可以动态的生成 Web 内容 . . .

Servlet 帮助我们处理了 TCP 连接，解析 HTTP 协议这些底层繁琐的工作，我们可以只看传来的 Request 内容是什么，然后根据一系列（或是简单的处理流程）程序来送回 Response 。

### 3. 1  Servlet 结构





