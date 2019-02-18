#pragma once
#include "Python.h"
class GIL
{
public:
	GIL();
	~GIL();
private:
	PyGILState_STATE state;
};

