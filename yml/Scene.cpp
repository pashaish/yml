#include "Scene.h"

Scene::Scene(std::vector<IProp*>* props)
{
	this->props = props;
}

std::vector<IProp*> *Scene::get_props()
{
	return this->props;
}
