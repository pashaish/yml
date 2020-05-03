#include "Rect.h"

Rect::Rect(sf::Vector2f *pos, sf::Vector2f *size, std::vector<IProp*> *children) : Prop(pos, children)
{
	this->size = size;

}

void Rect::render(sf::RenderWindow* window)
{
	auto rect = new sf::RectangleShape(*this->size);
	rect->setPosition(*this->position);
	rect->setFillColor(sf::Color(255, 255, 255));
	window->draw(*rect);
}

b2Shape* Rect::create_shape()
{
	auto rect = new b2PolygonShape();
	rect->SetAsBox(this->size->x, this->size->y);
	return rect;
}
