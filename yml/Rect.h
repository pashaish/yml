#pragma once
#include "Prop.h"

class Rect :
	public Prop
{
public:
	Rect(sf::Vector2f *pos, sf::Vector2f *size, std::vector<IProp*> *children);
	void render(sf::RenderWindow* window) override;
	b2Shape* create_shape() override;
	sf::Vector2f *get_center_position() override;
protected:
	sf::Vector2f* size;
};

