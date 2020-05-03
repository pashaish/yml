#include <iostream>
#include "Engine.h"
#include "Scene.h"
#include "RenderProcessor.h"

int main()
{

	Engine* engine = new Engine(
		new Scene(
			new std::vector<IProp*>({})
		),
		new std::vector<IProcessor*>({
			new RenderProcessor(
				new sf::RenderWindow(
					sf::VideoMode(800, 600),
					"Title"
				)
			)
		})
	);

	engine->run();
}
