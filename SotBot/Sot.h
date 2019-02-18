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


	static std::string getAppDirectory();


	static int32_t getToken();


	static const char *getCookies();


	static int send(GroupMsg msg);


	static int log(Log log);

	static void ban(Group group);

	static void ban(Group group,Member member, int64_t duration);

	static void unban(Group group);

	static void unban(Group group, Member member);

};