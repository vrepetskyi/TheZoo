#pragma once

#include "IAnimalFactory.h"
#include "Animal.h"

class StrictAnimalFactory : public IAnimalFactory
{
public:
	Animal* createRandom();
};
