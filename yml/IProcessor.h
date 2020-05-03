#pragma once
#include "IProp.h";

class IProcessor {
public:
	virtual void process(std::vector<IProp*>* prop) = 0;
};