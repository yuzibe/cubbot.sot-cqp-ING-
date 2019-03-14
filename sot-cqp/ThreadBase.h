#pragma once
#include "stdafx.h"

#include "thread"
#include "mutex"

class ThreadBase
{
public:
	virtual void start();
	virtual void quit();
protected:
	virtual void threadMain() = 0;
private:
	std::mutex mutex;
	std::thread * thisThread = nullptr;
	bool isQuit = true;
};
