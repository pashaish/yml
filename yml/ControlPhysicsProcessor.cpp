#include "ControlPhysicsProcessor.h"

ControlPhysicsProcessor::ControlPhysicsProcessor(sf::RenderWindow* window, IProp *control_prop) : PhysicsProcessor()
{
	this->window = window;
	this->control_prop = control_prop;
}

void ControlPhysicsProcessor::process(std::vector<IProp*>* props)
{
	sf::Event evnt;
	auto* body = this->get_body(this->control_prop);

	while(this->window->pollEvent(evnt))
	{
		if (evnt.key.code == sf::Keyboard::Space)
		{
			std::printf("fw");
			body->ApplyLinearImpulseToCenter(b2Vec2(10, -500), true);
			body->ApplyForceToCenter(b2Vec2(10, -500), true);
		}
	}
	PhysicsProcessor::process(props);
}
