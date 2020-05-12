#include "PhysicsController.h"

#include <iostream>

PhysicsController::PhysicsController(IProp* control_prop, sf::RenderWindow* window, PhysicsProcessor* processor)
{
	this->control_prop = control_prop;
	this->window = window;
	this->processor = processor;
}

void PhysicsController::process()
{
	auto* evnt = new sf::Event();
	auto* body = this->processor->get_body(this->control_prop);

	while (this->window->pollEvent(*evnt))
	{
		switch (evnt->type)
		{
		case sf::Event::Closed:
			*this->is_run = false;
			break;
		}
	}
	this->is_left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	this->is_right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	this->is_space = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

	auto velocity = body->GetLinearVelocity();
	
	if (this->is_left && std::abs(velocity.x) > 10)
	{
		velocity.x -= 1;
	}
	if (this->is_right && std::abs(velocity.x) > 10)
	{
		velocity.x += 1;
	}
	if (this->is_space)
	{
		velocity.y = -20;
	}

	body->SetLinearVelocity(velocity);
}  
