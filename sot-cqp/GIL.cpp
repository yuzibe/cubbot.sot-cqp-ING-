#include "stdafx.h"
#include "GIL.h"


GIL::GIL()
{
	state = PyGILState_Ensure();
}


GIL::~GIL()
{
	PyGILState_Release(state);
}
