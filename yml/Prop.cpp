#include "Prop.h"

Prop::Prop(sf::Vector2f *pos, std::vector<IProp*>* children)
{
	this->children = children;
	this->position = pos;
}

void Prop::render(sf::RenderWindow* window)
{
	
}

std::vector<IProp*>* Prop::get_children()
{
	return this->children;
}

void Prop::set_position(sf::Vector2f *pos)
{
	this->position = pos;
}

sf::Vector2f* Prop::get_position()
{
	return this->position;
}

float Prop::get_friction()
{
	return this->friction;
}

void Prop::set_friction(float friction)
{
	this->friction = friction;
}

float Prop::get_density()
{
	return this->density;
}

void Prop::set_density(float density)
{
	this->density = density;
}

b2BodyType Prop::get_body_type()
{
	return this->body_type;
}

void Prop::set_body_type(b2BodyType type)
{
	this->body_type = type;
}

sf::Vector2f *Prop::get_center_position()
{
	return this->position;
}

float Prop::get_rotation()
{
	return this->rotation;
}

void Prop::set_rotation(float rotation)
{
	this->rotation = rotation;
}
