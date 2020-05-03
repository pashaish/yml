#pragma once
#include <vector>
#include "SFML/Graphics.hpp";

class IProp {
public:
	virtual void render(sf::RenderWindow *window) {};
	virtual std::vector<IProp*>* get_children() {};
};