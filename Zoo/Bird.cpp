#include "Animal.h"
#include "Bird.h"

Bird::Bird(int expected_breedings, Reproductivity reproductivity, int cubs_per_pregnancy, bool can_fly) :
	Animal::Animal(expected_breedings, reproductivity, cubs_per_pregnancy),
	can_fly{ can_fly } {}

Bird::Bird(const Bird& d, const Animal& r) :
	Animal::Animal(d, r), can_fly{ d.can_fly } {}

const std::string Bird::toString() const
{
	return Animal::toString() + " It " + (can_fly ? "can" : "cannot") + " fly.";
}
