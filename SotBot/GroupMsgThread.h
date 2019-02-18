#pragma once
#include "stdafx.h"

#include "queue"

#include "cqp.h"

#include "ThreadBase.h"
#include "GroupMsg.h"

class ComponentManage;

class GroupMsgThread :
	public ThreadBase
{
public:
	void start();
	void quit();
	void push(GroupMsg msg);
private:
	GroupMsgThread();
	~GroupMsgThread();
	virtual void threadMain();
private:
	std::queue<GroupMsg> msgBuffer;
	std::mutex mutex;
	bool isQuit = true;
	friend ComponentManage;
};