#include "stdafx.h"

#include "Member.h"

Member::Member()
{

}


Member::Member(int64_t id)
{
	this->id = id;

}


Member::~Member()
{

}

int64_t Member::getId()
{
	return id;
}

