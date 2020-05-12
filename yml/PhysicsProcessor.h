#pragma once
#include "IProcessor.h"
#include "Box2D.h"
#include <map>

class PhysicsProcessor :
	public IProcessor
{
public:
	PhysicsProcessor();
	void process(std::vector<IProp*>* props) override;
	b2Body* get_body(IProp* prop) const;
	bool is_cycle;
protected:
	b2World* world;
	std::map<IProp*, b2Body*>* bodies;
};

