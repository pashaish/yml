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
protected:
	std::vector<IProp*>* children;
	sf::Vector2f *position;
};

