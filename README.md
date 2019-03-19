## sot-cqp 文档 

 [![Build status](?svg=true)]()

sot-cqp 允许你通过 Python 等语言写一个消息处理器, 通过sot-cqp 调用, 你无需关心去实现得到 QQ 的私聊或者群组消息, 你只需要关心字符串, 图像, 语言之间的处理即可, sot-cqp 通过使用酷 Q 提供的文档二次开发而来. 

### 1. 开发 QA (几个误会的澄清) 

Q: 为什么要使用 sot-cqp 而不使用酷 Q 提供的 API  

A: 酷 Q 官方只提供了仅有的几个 api 的调用版本, 目前包括易语言和 VC 这两个主要版本. 易语言由于流行程度导致很多人需要重新去学习易语言的语法; VC 因为其众所周知的网络请求调用所诟病. sot-cqp 是我研究了 Python3.7 文档中的 Python/C API 实现了 C 调用 Python 发送请求或者在 Pyhton 内出来, 在将结果从Python 中放回到 C 程序中. 更重要的原因, 我认为则是酷 Q 只是提供了一套接受和发送 QQ 消息的 SDK 而并没有提供 DEMO, 而在 QQ 群中消息往往是高并发的, 需要有相关开发经验才能将问题解决, 而并不值得主要在消息或者语言处理的 Python 工作者折腾.   
 
### 2. 当下, 前景

当下, 已经解决的问题:   

- ~~API以及主要代码OOP风格~~
- ~~多线程处理以及其管理~~
- ~~异步和消息队列~~
- ~~Python的全局锁 GIL~~
- ~~集成式的组件管理~~


前景, 还未解决的问题:  

- 界面
- …   

前景有无限可能, 希望你在 Iusse 中提及.  

### 3. 物料, 食用说明书

**物料准备**

- VS2017  
[下载地址](https://visualstudio.microsoft.com/zh-hans/thank-you-downloading-visual-studio/?sku=Enterprise&rel=15)

- Python 3.7 + request   
[下载地址](https://www.python.org/ftp/python/3.7.2/python-3.7.2.exe)

- 酷Q  
[下载地址](http://dlsec.cqp.me/cqa-tuling)

- 可选
    - 图灵 API
    - Python 实现图灵调用的 DEMO

**食用说明**  

VS2017 

设置 `Python` 环境并编译项目



您可以编译为 `cn.son9wx.cubbot.sot-cqp.dll`，与 `sot-cqp/cn.son9wx.cubbot.sot-cqp.json` 一起放置在 酷Q 的 app 目录下测试

`sot-cqp/cn.son9wx.cubbot.sot-cqp.json` - 样例应用的对应信息文件，包含应用的基础信息、事件列表等，请放置在 酷Q 的 app 目录下 (无需使用的事件、菜单、权限请在此删除) 

在程序修改完成后, 可以自己打包成任何形式的程序. 

如果你需要修改 `appid` 可以将  `cn.son9wx.cubbot.sot-cqp.dll` 和`cn.son9wx.cubbot.sot-cqp.json` 和修改 `appmain.h` 中的配置, 只需要确保三个地方是一样的即可.  


 
将生成的 dll 文件和 json 一起放置在酷 Q 文件目录下, Py 文件放入更目录下即可, 如果你需要自定义目录, 在Tuling文件中进行修改. 和人工智障一起愉快的聊天吧
 
### 4. 走心聊天

首先, 先要知道Sot的基本对象, 成员, 群组, 消息类间关系下图胜过千言万语. 

#### - OOP 风格  
习惯了OOP很多年, 总感觉cqp提供的api非常别扭, 代码写出来没有语义化, 通常需要注解才能理解, 所以采用了OOP和语义化的代码开发和方法定义, 减缓开发者的压力.  


下面就是基于 `OOP` 风格的二次开发, 代码简洁易懂, 没有罗嗦的成分. 

```cpp
class Sot
{
public:

	// 获取应用程序的所在路径
	static std::string getAppDirectory();

	// 获取当前账号的TOKEN
	static int32_t getToken();

	// 获取当前账号的Cookies
	static const char *getCookies();

	// 发送消息
	static int send(GroupMsg msg);
	static int send(PrivateMsg msg);

	// 调试日志
	static int log(Log log);

	// 禁言相关
	// 全员禁言
	static void ban(Group group);

	// 群成员禁言
	// ttl 禁言时常
	static void ban(Group group,Member member, int64_t ttl);

	// 全员解禁
	static void unban(Group group);

	// 群成员解禁
	static void unban(Group group, Member member);

};
```


很多人问我怎样才算 `OOP` 风格, 最早接触到 OOP 风格实在看 <<Java 疯狂讲义>> 的时候看到的, 俗话讲就是 C 语言是 `🐖.🚿()` 和 `🚿(🐖)` 这样最直接的体现, 但是 `OOP` 风格不代表 `OOP` 本身, 他还是需要满足几个特性, 封装, 多态, 继承. 
 
#### - 多线程处理以及其管理  
解耦, 利用中间件管理各个线程, 一个线程的错误不会影响到其他线程的运行.

下面这个 DEMO 给了大家一个简单的管理定义. 

```cpp
ComponentManage * ComponentManage::getInstance()
{
	static ComponentManage* componentManage
		= new ComponentManage();
	return componentManage;
}

GroupMsgThread * ComponentManage::getGroupMsgThreadInstance()
{
	return groupMsgThreadInstance;
}
```

使用 `ComponentManage::getInstance()->getGroupMsgThreadInstance()->start();`  进入组件管理的组件或者线程的创建和销毁我们无需关心, 只需要开启和停止线程即可, 解耦的同时还简化的开发的复杂度. 

#### - GIL  
痛苦, 没有教程需要自己摸索, 这里把我实现的方式展示给大家.  

1. 初始化 可以全局初始化一次也可以调用前执行

```cpp
Py_Initialize();
PyEval_InitThreads();
PyEval_ReleaseThread(PyThreadState_Get());
```

2. 状态锁随类创建和销毁

```cpp
GIL::GIL(){	state = PyGILState_Ensure();}
GIL::~GIL(){	PyGILState_Release(state);}
```

3. 调用 Python 

```cpp
GIL gil;

PyObject *modules = nullptr;
PyObject *func = nullptr;
PyObject *args = nullptr;
PyObject *res = nullptr;

modules = PyImport_ImportModule("TuLing"); // 位置就是 dll 当前目录 

func = PyObject_GetAttrString(modules, "TuLing");

args = PyTuple_New(1);
const char * contentUtf = G2U(content.c_str());

PyTuple_SetItem(args, 0, Py_BuildValue("s", contentUtf));
Sot::log(Log(LOG_INFO, "Py", content));

res = PyObject_CallObject(func, args);
char* ret_str;
if (res != NULL)
    PyArg_Parse(res, "s", &ret_str);

const char * contentGbk = U2G(ret_str);

Py_DECREF(args);
Py_DECREF(func);
Py_DECREF(res);
Py_DECREF(modules);

res = nullptr;
args = nullptr;
func = nullptr;
modules = nullptr;

return std::string(contentGbk);
```

#### - 异步和消息队列  
异步处理消息接受和消息处理以及发送, 不需要担心因为信息过多而导致不可预计的问题的出现. 

```cpp
void GroupMsgThread::push(GroupMsg msg)
{
	if (msgBuffer.size() < 100)
	{
		mutex.lock();
		msgBuffer.push(msg);
		mutex.unlock();
	}
}

void GroupMsgThread::threadMain()
{
	while (!isQuit)
	{
		if (msgBuffer.size() > 0)
		{
			mutex.lock();
			GroupMsg msg = msgBuffer.front();
			msgBuffer.pop();
			mutex.unlock();
			
/*------------------------------TuLing-----------------------------------------*/
			GroupMsg reply(TuLing::getResContent(msg.getContent()), msg.Group::getId());
			Sot::send(reply);
/*------------------------------TuLing-----------------------------------------*/

		}
		else
		{
			Sleep(100);
		}
	}
	return;
}
```

这里注意互斥锁即可. 

#### - 编码  
酷Q不支持UTF8, 而在 Python3.x 是统一 unicode 编码的, 无论在哪边都需要做一次统一的编码. 

```cpp
char* U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

char* G2U(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}
```


### 5. 参考资料, 致谢

- 感谢Python官方的文档  
Python 3.7.2 Doc https://docs.python.org/3.6/c-api/index.html

- 感谢酷Q团队的SDK和文档  
SDK (VC) https://github.com/CoolQ/cqsdk-vc/archive/master.zip  
主站：https://cqp.cc  
文库：https://d.cqp.me 
