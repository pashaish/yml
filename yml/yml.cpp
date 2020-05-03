#include <iostream>
#include "Engine.h"
#include "Scene.h"
#include "RenderProcessor.h"
#include "PhysicsProcessor.h"
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
	
	auto *engine = new Engine(
		new Scene(
			new std::vector<IProp*>({
				new Rect(
					new sf::Vector2f(40, 10),
					new sf::Vector2f(100, 200),
					new std::vector<IProp*>({})
				),
				ground
			})
		),
		new std::vector<IProcessor*>({
			new RenderProcessor(
				new sf::RenderWindow(
					sf::VideoMode(800, 600),
					"Title"
				)
			),
			new PhysicsProcessor()
		})
	);

	engine->run();
}
