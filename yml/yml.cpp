#include <iostream>
#include "Engine.h"
#include "PhysicsProcessor.h"
#include "PhysControlProcessor.h"
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
		new sf::Vector2f(30, 30),
		new std::vector<IProp*>({})
	);
	
	auto *engine = new Engine(
		new Scene(
			new std::vector<IProp*>({
				rect,
				ground
			})
		),
		new std::vector<IProcessor*>({
			new PhysControlProcessor(
				new PhysicsProcessor(),
				rect
			),
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
