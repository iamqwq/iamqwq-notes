```
GET /somedir/page.html HTTP/1.1
Host: www.xxx.com
Connection: close
User-agent: Mozilla/5.0
Accept-language: en
```

第一行为请求行（ request line ），而后继的行叫做首部行（ header line ）。

通用首部行：

```
Date:
// 报文的创建时间
Connection:
// 连接状态
Via:
// 显示报文经过的中间节点
Cache-Control:
// 缓存控制（如缓存时长）
MIME-Version:
// 邮件协议版本
```

请求首部行：

```
Accept:
// 通知服务器客户端可接受的媒体类型
Accept-Charset:
// 客户端可接受的字符集
Accept-Encoding:
// 客户端可接受的编码格式
Accept-Language:
// 客户端可接受的语言
Client-IP:
// 请求的客户端IP
Host:
// 请求的服务器名称和端口
Referer:
// 跳转至当前URL的前一个页面URL
User-Agent:
// 指明浏览器类型
```

安全请求首部行：

```
Authorization:
// 向服务器发送认证信息
Cookie:
// 客户端向服务器发送cookie
Cookie2:
// 指明客户端支持的cookie版本
Proxy-Authorization:
// 向代理服务器认证
```

