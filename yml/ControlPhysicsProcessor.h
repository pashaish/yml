#pragma once
#include "PhysicsProcessor.h"
class ControlPhysicsProcessor :
	public PhysicsProcessor
{
public:
	ControlPhysicsProcessor(sf::RenderWindow* window, IProp *control_prop);
	void process(std::vector<IProp*>* prop) override;
protected:
	sf::RenderWindow* window;
	IProp *control_prop;
};

