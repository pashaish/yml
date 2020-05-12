#pragma once
#include "./IScene.h"
#include "./IProcessor.h"
#include <vector>
#include "IController.h";

class Engine
{
public:
	Engine(IScene* scene, std::vector<IProcessor*>* processors);
	void run();
	void stop();
protected:
	bool is_run = false;
	IScene *scene;
	std::vector<IProcessor*> *processors;
};

