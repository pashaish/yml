#include "Engine.h"
#include <thread>


void Engine::run()
{
	this->is_start = true;
	while (this->is_start) {
		for (IProcessor *processor : *this->processors) {
			processor->process(this->scene->get_props());
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));
	}
}

void Engine::stop()
{
	this->is_start = false;
}
