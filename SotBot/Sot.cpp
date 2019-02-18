#pragma once
#include "stdafx.h"
#include "Sot.h"

extern int ac;

std::string Sot::getAppDirectory()
{

	return std::string(CQ_getAppDirectory(ac));
}

int Sot::send(GroupMsg msg)
{
	return CQ_sendGroupMsg(ac, msg.Group::getId(), msg.getContent().c_str());
}




int Sot::log(Log log)
{
	return CQ_addLog(ac, log.getPriority(), log.getCategory().c_str(), log.getContent().c_str());
}



int32_t Sot::getToken()
{
	return CQ_getCsrfToken(ac);
}

const char * Sot::getCookies()
{
	return CQ_getCookies(ac);
}


void Sot::ban(Group group)
{
	bool ban = true;
	CQ_setGroupWholeBan(ac, group.getId(), ban);
}

void Sot::ban(Group group, Member member, int64_t duration)
{
	CQ_setGroupBan(ac, group.getId(), member.getId(), duration);
}

void Sot::unban(Group group, Member member)
{
	CQ_setGroupBan(ac, group.getId(), member.getId(), 0);
}

void Sot::unban(Group group)
{
	bool ban = false;
	CQ_setGroupWholeBan(ac, group.getId(), ban);
}



