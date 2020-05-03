#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include "Box2D.h"

class IProp {
public:
	virtual void render(sf::RenderWindow *window) = 0;
	virtual std::vector<IProp*>* get_children() = 0;
	virtual void set_position(sf::Vector2f *pos) = 0;
	virtual sf::Vector2f *get_position() = 0;
	virtual b2Shape* create_shape() = 0;
};