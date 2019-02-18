#pragma once
#include "GroupMsgThread.h"
#include "Sot.h"
class GroupMsgThread;

class ComponentManage
{
public:

	static ComponentManage* getInstance();
	
	GroupMsgThread* getGroupMsgThreadInstance();
private:
	ComponentManage();
	~ComponentManage();

	

};

