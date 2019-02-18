#pragma once
#include "stdafx.h"
class Member
{
public:
	Member();
	~Member();
	Member(int64_t id);
	int64_t getId();
private:
	int64_t id;
};

