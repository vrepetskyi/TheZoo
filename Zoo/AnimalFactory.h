#pragma once

#include "IAnimalFactory.h"
#include "Animal.h"

class AnimalFactory : public IAnimalFactory
{
public:
	Animal* createRandom();
};
