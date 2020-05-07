#pragma once
#include "IProp.h"

class IController
{
public:
	bool* is_run = 0;
	virtual void process() = 0;
};
