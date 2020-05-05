#include "Engine.h"
#include <thread>
#include <mutex>


Engine::Engine(IScene* scene, std::vector<IProcessor*>* processors, IController* controller) {
	this->scene = scene;
	this->processors = processors;
	this->controller = controller;
}

void Engine::run()
{
	this->is_run = true;

	std::vector<std::thread*> threads;

	for (auto* processor : *this->processors)
	{
		auto* mtx = new std::mutex();

		auto threadCallback = [processor, this, mtx]()
		{
			new std::lock_guard<std::mutex>(*mtx);
			
			while (this->is_run)
			{
				processor->process(this->scene->get_props());
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		};
		auto* thread = new std::thread(threadCallback);
		threads.push_back(thread);
	}
	while (this->is_run)
	{
		this->controller->process();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	for (auto* thread : threads)
	{
		thread->join();
	}
}

void Engine::stop()
{
	this->is_run = false;
}
