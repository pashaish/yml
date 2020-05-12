#pragma once
#include "IProcessor.h"
#include "PhysicsProcessor.h"

class PhysControlProcessor :
	public IProcessor
{
public:
	PhysControlProcessor(PhysicsProcessor* processor, IProp* control_prop);
	void process(std::vector<IProp*>* props) override;
protected:
	PhysicsProcessor* processor;
	IProp* control_prop;
};

