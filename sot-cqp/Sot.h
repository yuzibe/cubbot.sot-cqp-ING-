#pragma once
#include "stdafx.h"

#include "string"

#include "cqp.h"

#include "Member.h"
#include "Group.h"
#include "GroupMsg.h"
#include "Log.h"

class Sot
{
public:

	// 获取应用程序的所在路径
	static std::string getAppDirectory();

	// 获取当前账号的TOKEN
	static int32_t getToken();

	// 获取当前账号的Cookies
	static const char *getCookies();

	// 发送消息
	static int send(GroupMsg msg);

	static int log(Log log);

	// 全员禁言
	static void ban(Group group);

	// 群成员禁言
	static void ban(Group group,Member member, int64_t duration);

	// 全员解禁
	static void unban(Group group);

	// 群成员解禁
	static void unban(Group group, Member member);

};