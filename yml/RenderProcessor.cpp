#include "RenderProcessor.h"

RenderProcessor::RenderProcessor(sf::RenderWindow *window)
{
	this->window = window;
	this->window->setFramerateLimit(120);
}

void RenderProcessor::process(std::vector<IProp*>* props)
{
	this->window->setActive(true);
	std::printf("Helo \n");

	while(this->window->isOpen())
	{
		auto prop_render = [this](IProp* prop)
		{
			prop->render(this->window);
			for (auto *ch : *prop->get_children())
			{
				ch->render(this->window);
			}
		};
		auto* evnt = new sf::Event();

		while (this->window->pollEvent(*evnt))
		{
			std::printf("Helo \n");
		}
		this->window->clear();

		for (IProp *prop : *props) {
			prop_render(prop);
		}
		
		this->window->display();
	}

	this->window->setActive(false);
}
