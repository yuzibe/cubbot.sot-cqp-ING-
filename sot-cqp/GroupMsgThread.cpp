#pragma once
#include "stdafx.h"

#include "GroupMsgThread.h"
#include "Sot.h"
#include "GroupMsg.h"
#include "TuLing.h"

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

GroupMsgThread::GroupMsgThread()
{
	isQuit = false;
}

GroupMsgThread::~GroupMsgThread()
{
}

void GroupMsgThread::start()
{
	ThreadBase::start();
	isQuit = false;
}

void GroupMsgThread::quit()
{

	ThreadBase::quit();
	isQuit = true;
}