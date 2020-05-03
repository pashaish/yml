#include "PhysicsProcessor.h"
#include <iostream>

PhysicsProcessor::PhysicsProcessor()
{
	this->world = new b2World(b2Vec2(0.5, 10));
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
	b2Body *body;

	if (this->bodies->find(prop) == this->bodies->end())
	{
		auto* def = new b2BodyDef();
		def->gravityScale = 10;
		def->type = prop->get_body_type();
		
		const sf::Vector2f* position = prop->get_position();

		def->position.Set(position->x, position->y);

		body = this->world->CreateBody(def);

		std::pair<IProp*, b2Body*> pair(prop, body);

		this->bodies->insert(pair);
	} else
	{
		body = this->bodies->at(prop);
	}

	auto* fixture = body->GetFixtureList();
	
	if (fixture == nullptr || prop->get_density() != fixture->GetDensity() || prop->get_friction() != fixture->GetFriction())
	{
		auto* fixture_def = new b2FixtureDef();
		fixture_def->shape = prop->create_shape();
		
		fixture_def->density = prop->get_density();
		fixture_def->friction = prop->get_friction();
		
		body->DestroyFixture(fixture);
		body->SetType(prop->get_body_type());
		
		body->CreateFixture(fixture_def);
	}
	
	
	return body;
}
