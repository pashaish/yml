#include <iostream>
#include "Engine.h"
#include "Scene.h"
#include "RenderProcessor.h"
#include "ControlPhysicsProcessor.h"
#include "Rect.h"

int main()
{
	setlocale(LC_ALL, "ru");

	auto *ground = new Rect(
		new sf::Vector2f(20, 400),
		new sf::Vector2f(300, 50),
		new std::vector<IProp*>({})
	);
	ground->set_body_type(b2_staticBody);

	auto* rect = new Rect(
		new sf::Vector2f(140, 10),
		new sf::Vector2f(100, 200),
		new std::vector<IProp*>({})
	);
	
	auto* window = new sf::RenderWindow(
		sf::VideoMode(800, 600),
		"Title"
	);
	window->setActive(false);
	
	auto *engine = new Engine(
		new Scene(
			new std::vector<IProp*>({
				rect,
				ground
			})
		),
		new std::vector<IProcessor*>({
			new PhysicsProcessor(),
			// new ControlPhysicsProcessor(
				// window,
				// rect
			// ),
			new RenderProcessor(
				window
			)
		})
	);

	engine->run();
}
