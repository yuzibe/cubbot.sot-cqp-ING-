#pragma once
#include "stdafx.h"
#include "Group.h"
#include "Member.h"

class ComponentManage;

class GroupMsg:public Group,public Member
{
public:
	GroupMsg();
	GroupMsg(int32_t msgId, std::string msg, int64_t fromGroup, int64_t fromQQ);
	GroupMsg(std::string msg, int64_t toGroup);
	~GroupMsg();
	int32_t getId();
	std::string getContent();
	friend ComponentManage;
private:
	int32_t id;
	std::string content;
};