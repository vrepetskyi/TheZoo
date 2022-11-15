#pragma once

#include "Animal.h"

class IAnimalFactory
{
public:
	virtual Animal* createRandom() = 0;
};
