#include "Animal.h"
#include "Bird.h"
#include "Eagle.h"
#include <cmath>
#include <string>

std::string drones[5]{
	"Mavic", "Mini", "Air", "Phantom", "FPV" };

Eagle::Eagle(Reproductivity reproductivity) : Bird::Bird(5, reproductivity, 2, true), favourite_drone{ drones[std::rand() % 5] } {}

Eagle::Eagle(const Eagle& d, const Animal& r) : Bird::Bird(d, r), favourite_drone{ d.favourite_drone } {}

const std::string Eagle::getKind() const
{
	return "Eagle";
}

Animal* Eagle::breed(const Animal& partner) const
{
	return new Eagle(*this, partner);
}

const std::string Eagle::toString() const
{
	return Bird::toString() + " Its favourite drone is " + favourite_drone + '.';
}
