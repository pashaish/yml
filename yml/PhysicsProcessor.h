#pragma once
#include "IProcessor.h"
#include "Box2D.h"
#include <map>

class PhysicsProcessor :
	public IProcessor
{
public:
	PhysicsProcessor();
	void process(std::vector<IProp*>* prop) override;
	b2Body* get_body(IProp* prop) const;
protected:
	b2World* world;
	std::map<IProp*, b2Body*>* bodies;
};

