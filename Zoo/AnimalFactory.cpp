#include "AnimalFactory.h"
#include "Animal.h"
#include "Bear.h"
#include "Cuttlefish.h"
#include "Eagle.h"
#include "Hare.h"
#include "Penguin.h"
#include "Salmon.h"
#include <cmath>

Animal* AnimalFactory::createRandom()
{
	switch (std::rand() % 6)
	{
	case 0:
		return new Salmon(Reproductivity::ANY);
		break;
	case 1:
		return new Cuttlefish(Reproductivity::ANY);
		break;
	case 2:
		return new Penguin(Reproductivity::ANY);
		break;
	case 3:
		return new Penguin(Reproductivity::ANY);
		break;
	case 4:
		return new Hare(Reproductivity::ANY);
		break;
	case 5:
		return new Bear(Reproductivity::ANY);
		break;
	}
}
