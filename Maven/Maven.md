# Maven

## 1 浅谈 Maven

> **Apache Maven**，是一个[软件](https://zh.m.wikipedia.org/wiki/软件)（特别是[Java](https://zh.m.wikipedia.org/wiki/Java_(编程语言))软件）[项目管理](https://zh.m.wikipedia.org/wiki/项目管理)及[自动构建](https://zh.m.wikipedia.org/wiki/自动构建)工具，由[Apache软件基金会](https://zh.m.wikipedia.org/wiki/Apache软件基金会)所提供。

当一个项目需要大量第三方组件的支持才能正常运行的时候，在各个开源网站中下载和仔细的挑选正确的版本无疑是一件繁琐的事情。因此 Maven 提供了一个 Maven 仓库的概念，当需要一个第三方组件时，只需要在配置文件中注明详细信息，即可快速下载依赖。这很大程度的节省了构建项目的时间。

## 2 坐标属性

Maven 对于一个项目的唯一标识依靠三项属性，分别是 groupId artifactId 和 version 。groupId 标注 Maven 项目隶属的组织 / 公司名称，artifactId 标注实际项目的一个 Maven 模块 / 项目名称，version 标注的是 Maven 项目当前所处的版本。

如果想要引用 Maven 项目，同样使用上述三项属性来唯一标识需要引用的依赖。



