#include "stdafx.h"

#include "GroupMsg.h"


GroupMsg::GroupMsg()
{

}

GroupMsg::GroupMsg(int32_t msgId, std::string msg, int64_t fromGroup, int64_t fromQQ) : Group(fromGroup), Member(fromQQ)
{
	this->id = msgId;
	this->content = msg;
}

GroupMsg::GroupMsg(std::string msg, int64_t toGroup) :  Group(toGroup)
{
	this->content = msg;
}

GroupMsg::~GroupMsg()
{

}

int32_t GroupMsg::getId()
{
	return id;
}

std::string GroupMsg::getContent()
{
	return content;
}
