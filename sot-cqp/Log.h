#pragma once
#include "stdafx.h"
#include "string"

#define LOG_DEBUG 0           //调试 灰色
#define LOG_INFO 10           //信息 黑色
#define LOG_INFOSUCCESS 11    //信息(成功) 紫色
#define LOG_INFORECV 12       //信息(接收) 蓝色
#define LOG_INFOSEND 13       //信息(发送) 绿色
#define LOG_WARNING 20        //警告 橙色
#define LOG_ERROR 30          //错误 红色


class Log
{
public:
	Log();
	Log::Log(int32_t priority,
		std::string category,
		std::string content);
	~Log();
	int32_t getPriority();
	std::string getCategory();
	std::string getContent();
private:
	int32_t priority;
	std::string category;
	std::string content;
};

