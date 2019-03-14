#include "stdafx.h"
#include "Log.h"


Log::Log()
{
}

Log::Log(int32_t priority,
	std::string category,
	std::string content)
{
	this->priority = priority;
	this->category = category;
	this->content = content;
}

Log::~Log()
{
}

int32_t Log::getPriority()
{
	return priority;
}

std::string Log::getCategory()
{
	return category;
}

std::string Log::getContent()
{
	return content;
}
