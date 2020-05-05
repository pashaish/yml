#include "PhysicsController.h"

PhysicsController::PhysicsController(IProp* control_prop, sf::RenderWindow* window, PhysicsProcessor* processor)
{
	this->control_prop = control_prop;
	this->window = window;
	this->processor = processor;
}

void PhysicsController::process()
{
	auto* evnt = new sf::Event();

	while (this->window->pollEvent(*evnt))
	{
		if (evnt->key.code == sf::Keyboard::Space)
		{
			auto* body = this->processor->get_body(this->control_prop);
			body->ApplyLinearImpulseToCenter(b2Vec2(350, 0), true);
		}
	}
}
