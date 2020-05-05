#include "Rect.h"

Rect::Rect(sf::Vector2f *pos, sf::Vector2f *size, std::vector<IProp*> *children) : Prop(pos, children)
{
	this->size = size;
	this->body_type = b2_dynamicBody;
}

void Rect::render(sf::RenderWindow* window)
{
	auto* rect = new sf::RectangleShape(*this->size);
	rect->setPosition(*this->position);
	rect->rotate(this->get_rotation());
	rect->setFillColor(sf::Color(255, 255, 255));
	window->draw(*rect);
}

b2Shape* Rect::create_shape()
{
	auto* rect = new b2PolygonShape();
	
	b2Vec2 points[4] = {
		b2Vec2(0, 0),
		b2Vec2(this->size->x, 0),
		b2Vec2(this->size->x, this->size->y),
		b2Vec2(0, this->size->y),
	};
	rect->Set(points, 4);
	return rect;
}

sf::Vector2f *Rect::get_center_position()
{
	return new sf::Vector2f(
		this->position->x + (this->size->x / 2),
		this->position->y + (this->size->y / 2)
	);
}
