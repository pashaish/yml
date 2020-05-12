#include "PhysControlProcessor.h"

PhysControlProcessor::PhysControlProcessor(PhysicsProcessor* processor, IProp* control_prop)
{
	this->control_prop = control_prop;
	this->processor = processor;
}

void PhysControlProcessor::process(std::vector<IProp*>* props)
{
	this->processor->is_cycle = false;
	while(true)
	{
		auto* body = this->processor->get_body(this->control_prop);
		auto velocity = body->GetLinearVelocity();
		bool is_left = sf::Keyboard::isKeyPressed(sf::Keyboard::A) && std::abs(velocity.x) < 14;
		bool is_right = sf::Keyboard::isKeyPressed(sf::Keyboard::D) && std::abs(velocity.x) < 14;
		
		if (is_left)
		{
			velocity.x -= 1;
		}
		if (is_right)
		{
			velocity.x += 1;
		}
		body->SetLinearVelocity(velocity);
		this->processor->process(props);
	}
}
