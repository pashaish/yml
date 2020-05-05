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
	virtual float get_rotation() = 0;
	virtual void set_rotation(float rotation) = 0;
	virtual b2Shape* create_shape() = 0;
	virtual b2BodyType get_body_type() = 0;
	virtual float get_restitution() = 0;
	virtual void set_restitution(float restitution) = 0;
	virtual void set_body_type(b2BodyType type) = 0;
	virtual float get_friction() = 0;
	virtual void set_friction(float friction) = 0;
	virtual float get_density() = 0;
	virtual void set_density(float density) = 0;
	virtual sf::Vector2f *get_center_position() = 0;
};