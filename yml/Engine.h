#pragma once
#include "./IScene.h"
#include "./IProcessor.h"
#include <vector>

class Engine
{
public:
	Engine(IScene *scene, std::vector<IProcessor*> *processors) {
		this->scene = scene;
		this->processors = processors;
	}
	void run();
	void stop();
protected:
	bool is_start = false;
	IScene *scene;
	std::vector<IProcessor*> *processors;
};

