#include "stdafx.h"

#include "ThreadBase.h"

void ThreadBase::start()
{
	mutex.lock();
	if (thisThread == nullptr)
	{
		thisThread = new std::thread{ &ThreadBase::threadMain,this };
	}
	mutex.unlock();
}

void ThreadBase::quit()
{
	mutex.lock();
	if (thisThread != nullptr)
	{
		delete thisThread;
		thisThread = nullptr;
	}
	mutex.unlock();
}
