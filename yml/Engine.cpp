#include "Engine.h"
#include <thread>
#include <mutex>


Engine::Engine(IScene* scene, std::vector<IProcessor*>* processors) {
	this->scene = scene;
	this->processors = processors;
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
			mtx->lock();
			processor->process(this->scene->get_props());
			mtx->unlock();
		};
		auto* thread = new std::thread(threadCallback);
		threads.push_back(thread);
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
