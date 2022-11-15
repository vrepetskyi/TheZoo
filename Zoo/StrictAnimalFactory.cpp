#include "StrictAnimalFactory.h"
#include "Animal.h"
#include "Bear.h"
#include "Cuttlefish.h"
#include "Eagle.h"
#include "Hare.h"
#include "Penguin.h"
#include "Salmon.h"
#include <cmath>

Animal* StrictAnimalFactory::createRandom()
{
	switch (std::rand() % 6)
	{
	case 0:
		return new Salmon(Reproductivity::CAN_REPRODUCE);
		break;
	case 1:
		return new Cuttlefish(Reproductivity::SELF_REPRODUCTIVE);
		break;
	case 2:
		return new Penguin(Reproductivity::CAN_REPRODUCE);
		break;
	case 3:
		return new Penguin(Reproductivity::CAN_REPRODUCE);
		break;
	case 4:
		return new Hare(Reproductivity::CAN_REPRODUCE);
		break;
	case 5:
		return new Bear(Reproductivity::CAN_REPRODUCE);
		break;
	}
}
