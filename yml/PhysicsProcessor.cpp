#include "PhysicsProcessor.h"
#include <iostream>
#define M_PI 3.14159265358979323846


PhysicsProcessor::PhysicsProcessor()
{
	this->world = new b2World(b2Vec2(0, 25));
	this->bodies = new std::map<IProp*, b2Body*>();
	
}

void PhysicsProcessor::process(std::vector<IProp*>* props)
{
	this->world->Step(1.0f / 120.0f, 6, 2);

	for (auto* prop : *props)
	{
		auto* body = this->get_body(prop);
		const auto pos = body->GetPosition();

		prop->set_position(new sf::Vector2f(pos.x, pos.y));
		prop->set_rotation(body->GetAngle() * (180 / M_PI));
	}

}

b2Body* PhysicsProcessor::get_body(IProp* prop) const
{
	b2Body *body;

	if (this->bodies->find(prop) == this->bodies->end())
	{
		auto* def = new b2BodyDef();
		def->angle = prop->get_rotation() / (180 / M_PI);
		def->type = prop->get_body_type();
		
		const sf::Vector2f position = *prop->get_position();

		def->position.Set(position.x, position.y);

		body = this->world->CreateBody(def);

		std::pair<IProp*, b2Body*> pair(prop, body);

		this->bodies->insert(pair);
	} else
	{
		body = this->bodies->at(prop);
	}

	auto* fixture = body->GetFixtureList();
	
	if (fixture == nullptr 
		|| prop->get_density() != fixture->GetDensity() 
		|| prop->get_friction() != fixture->GetFriction()
		)
	{
		auto* fixture_def = new b2FixtureDef();
		fixture_def->shape = prop->create_shape();
		fixture_def->restitution = prop->get_restitution();
		fixture_def->density = prop->get_density();
		fixture_def->friction = prop->get_friction();
		body->DestroyFixture(fixture);
		body->SetType(prop->get_body_type());
		body->CreateFixture(fixture_def);
	}
	
	return body;
}
