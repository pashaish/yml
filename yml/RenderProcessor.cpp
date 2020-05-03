#include "RenderProcessor.h"

RenderProcessor::RenderProcessor(sf::RenderWindow *window)
{
	this->window = window;
	//this->window->setActive();
	//this->window->setFramerateLimit(60);
}

void RenderProcessor::process(std::vector<IProp*>* props)
{
	//this->window->clear();
	//
	//for (IProp *prop : *props) {
	//	prop->render(this->window);
	//}
	//
	//this->window->display();
}
