#include "PhysicsProcessor.h"
#include <iostream>

PhysicsProcessor::PhysicsProcessor()
{
	this->world = new b2World(b2Vec2(1, 10));
	this->bodies = new std::map<IProp*, b2Body*>();
}

void PhysicsProcessor::process(std::vector<IProp*>* props)
{
	for (auto* prop : *props)
	{
		this->world->Step(60, 6, 2);
		auto* body = this->get_body(prop);
		const auto pos = body->GetPosition();

		
		prop->set_position(new sf::Vector2f(pos.x, pos.y));
	}
}

b2Body* PhysicsProcessor::get_body(IProp* prop) const
{
	if (this->bodies->find(prop) == this->bodies->end())
	{
		auto* def = new b2BodyDef();
		def->type = b2_dynamicBody;
		def->gravityScale = 3;

		const sf::Vector2f* position = prop->get_position();

		def->position.Set(position->x, position->y);

		auto* body = this->world->CreateBody(def);

		auto* mass = new b2MassData();
		mass->mass = 10;
		body->SetMassData(mass);

		auto* fixture_def = new b2FixtureDef();
		fixture_def->shape = prop->create_shape();
		fixture_def->density = 1.0f;
		fixture_def->friction = 0.3f;
		
		body->CreateFixture(fixture_def);

		std::pair<IProp*, b2Body*> pair(prop, body);

		this->bodies->insert(pair);

		return body;
		
	} else
	{
		return this->bodies->at(prop);
	}
	
}
