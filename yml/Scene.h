#pragma once
#include "IScene.h"

class Scene : public IScene
{
public:
	Scene(std::vector<IProp*>* props);
	
	std::vector<IProp*> *get_props() override;
private:
	std::vector<IProp*> *props;
};

