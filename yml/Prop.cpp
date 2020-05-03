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
