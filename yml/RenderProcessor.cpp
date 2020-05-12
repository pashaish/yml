#include "RenderProcessor.h"

RenderProcessor::RenderProcessor(sf::RenderWindow *window)
{
	this->window = window;
	this->window->setActive(false);
}

void RenderProcessor::process(std::vector<IProp*>* props)
{
	this->window->setFramerateLimit(120);
	this->window->setActive(true);

	while (this->window->isOpen())
	{
		auto prop_render = [this](IProp* prop)
		{
			prop->render(this->window);
			for (auto* ch : *prop->get_children())
			{
				ch->render(this->window);
			}
		};
		this->window->clear();

		for (IProp* prop : *props) {
			prop_render(prop);
		}

		this->window->display();
	}
	
	this->window->setActive(false);
}
