#pragma once
#include "IController.h"
#include "PhysicsProcessor.h"

class PhysicsController :
	public IController
{
public:
	PhysicsController(IProp* control_prop, sf::RenderWindow* window, PhysicsProcessor* processor);
	void process() override;
protected:
	PhysicsProcessor* processor;
	IProp* control_prop;
	sf::RenderWindow* window;
	bool is_left;
	bool is_right;
	bool is_space;
};

