#pragma once
#include "IProp.h"
#include <vector>

class IScene {
public:
	virtual std::vector<IProp*>* get_props() = 0;
};