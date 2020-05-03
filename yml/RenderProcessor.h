#pragma once
#include "IProcessor.h"
#include <SFML/Graphics.hpp>;

class RenderProcessor :
	public IProcessor
{
public:
	RenderProcessor(sf::RenderWindow *window);
	void process(std::vector<IProp*>* prop) override;
private:
	sf::RenderWindow *window;
};

