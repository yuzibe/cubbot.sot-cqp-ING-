#include "stdafx.h"
#include "Group.h"


Group::Group()
{

}

Group::Group(int64_t id)
{
	this->id = id;

}


Group::~Group()
{

}

int64_t Group::getId()
{
	return id;
}
