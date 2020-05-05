#include <iostream>
#include "Engine.h"
#include "PhysicsProcessor.h"
#include "PhysicsController.h"
#include "Scene.h"
#include "RenderProcessor.h"
#include "Rect.h"

int main()
{
	setlocale(LC_ALL, "ru");

	auto *ground = new Rect(
		new sf::Vector2f(0, 100),
		new sf::Vector2f(150, 20),
		new std::vector<IProp*>({})
	);
	ground->set_body_type(b2_staticBody);

	auto* rect = new Rect(
		new sf::Vector2f(10, 10),
		new sf::Vector2f(150, 20),
		new std::vector<IProp*>({})
	);
	
	auto* window = new sf::RenderWindow(
		sf::VideoMode(800, 600),
		"Title"
	);

	auto* phys_processor = new PhysicsProcessor();
	
	window->setActive(false);
	
	auto *engine = new Engine(
		new Scene(
			new std::vector<IProp*>({
				rect,
				ground
			})
		),
		new std::vector<IProcessor*>({
			phys_processor,
			new RenderProcessor(
				window
			)
		}),
		new PhysicsController(
			rect,
			window,
			phys_processor
		)
	);

	engine->run();
}
