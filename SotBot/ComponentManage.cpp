#include "stdafx.h"
#include "ComponentManage.h"

static GroupMsgThread* groupMsgThreadInstance;

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


ComponentManage::ComponentManage()
{
	groupMsgThreadInstance
		= new GroupMsgThread();
}


ComponentManage::~ComponentManage()
{

	delete groupMsgThreadInstance;
}
