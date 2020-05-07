#pragma once
#include "IProp.h"

class IProcessor {
public:
	bool *is_run = 0;
	virtual void process(std::vector<IProp*>* props) = 0;
};