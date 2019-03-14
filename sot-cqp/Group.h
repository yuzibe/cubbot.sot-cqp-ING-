#pragma once
#include "stdafx.h"
class Group
{
public:
	Group();
	Group(int64_t id);
	~Group();
	int64_t getId();
	
private:
	int64_t id;
};

