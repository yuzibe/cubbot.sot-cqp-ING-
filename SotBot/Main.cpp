#include "stdafx.h"
#include "Main.h"

class ComponentManage;

Main::Main()
{
	if (Main::init()) {
		Sot::log(Log(LOG_INFO, "Sot", "Sot 机器人启动"));
	}
}


Main::~Main()
{
}

bool Main::init()
{

	ComponentManage::getInstance()->getGroupMsgThreadInstance()->start();
	Sot::log(Log(LOG_INFO, "Sot", "群组消息线程启动"));


	Py_Initialize();
	PyEval_InitThreads();
	PyEval_ReleaseThread(PyThreadState_Get());
	Sot::log(Log(LOG_INFO, "Sot", "Python 初始化成功"));

	
	return true;

}

