#pragma once
#include "IProp.h"
class Prop :
	public IProp
{
public:
	Prop(sf::Vector2f *pos, std::vector<IProp*> *children);
	void render(sf::RenderWindow* window) override;
	std::vector<IProp*>* get_children() override;
	void set_position(sf::Vector2f *pos) override;
	sf::Vector2f *get_position() override;
	float get_friction() override;
	void set_friction(float friction) override;
	float get_density() override;
	void set_density(float density) override;
	b2BodyType get_body_type() override;
	void set_body_type(b2BodyType type) override;
	sf::Vector2f *get_center_position() override;
	float get_rotation() override;
	void set_rotation(float rotation) override;
	float get_restitution() override;
	void set_restitution(float restitution) override;
protected:
	std::vector<IProp*>* children;
	sf::Vector2f *position;
	b2BodyType body_type = b2_staticBody;
	float density = 0.2;
	float rotation = 0;
	float friction = 0.1;
	float restitution = 0.2;
};

