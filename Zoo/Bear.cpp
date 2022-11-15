#include "Animal.h"
#include "Mammal.h"
#include "Bear.h"
#include <cmath>
#include <string>

std::string berries[5]{
	"Huckleberry", "Bunchberry", "Bearberries", "Crowberries", "Cloudberries" };

Bear::Bear(Reproductivity reproductivity) : Mammal::Mammal(5, reproductivity, 1, "Tundra"), favourite_berry{ berries[std::rand() % 5] } {}

Bear::Bear(const Bear& d, const Animal& r) : Mammal::Mammal(d, r), favourite_berry{ d.favourite_berry } {}

const std::string Bear::getKind() const
{
	return "Bear";
}

Animal* Bear::breed(const Animal& partner) const
{
	return new Bear(*this, partner);
}

const std::string Bear::toString() const
{
	return Mammal::toString() + " Its favourite berry is " + favourite_berry + '.';
}
