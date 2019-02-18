#include "stdafx.h"
#include "TuLing.h"
char* G2U(const char* gb2312);
char* U2G(const char* utf8);
TuLing::TuLing()
{
;
}



std::string TuLing::getResContent(std::string content)
{
	GIL gil;

	try
	{
		PyObject *modules = nullptr;
		PyObject *func = nullptr;
		PyObject *args = nullptr;
		PyObject *res = nullptr;


		modules = PyImport_ImportModule("TuLing");
	
		if (modules == nullptr)
		{
			throw "导入模块出错";
		}

		func = PyObject_GetAttrString(modules, "TuLing");
		if (func == nullptr)
		{
			throw "加载函数出错";
		}

		args = PyTuple_New(1);
		const char * contentUtf = G2U(content.c_str());

		PyTuple_SetItem(args, 0, Py_BuildValue("s", contentUtf));
		Sot::log(Log(LOG_INFO, "Py", content));
		if (args == nullptr)
		{
			throw "参数构造出错";
		}

		res = PyObject_CallObject(func, args);
		char* ret_str;
		if (res != NULL)
			PyArg_Parse(res, "s", &ret_str);
		const char * contentGbk = U2G(ret_str);

		Py_DECREF(args);
		Py_DECREF(func);
		Py_DECREF(res);
		Py_DECREF(modules);

		res = nullptr;
		args = nullptr;
		func = nullptr;
		modules = nullptr;
		
		return std::string(contentGbk);
	}
	catch (const char * e)
	{
		Sot::log(Log(LOG_INFO, "Py", e));
	}
	
}



TuLing::~TuLing()
{

}

char* U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

char* G2U(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}