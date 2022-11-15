#include "Animal.h"
#include "Mammal.h"
#include "Hare.h"
#include <cmath>
#include <string>

std::string fur_types[9]{
	"Agouti", "Black otter", "Blue steel", "Broken", "Chinchilla",
	"Castor", "Chocolate chinchilla", "Lilac tortoiseshell", "Sable marten" };

Hare::Hare(Reproductivity reproductivity) : Mammal::Mammal(3, reproductivity, 2, "Europe"), fur_type{ fur_types[std::rand() % 9] } {}

Hare::Hare(const Hare& d, const Animal& r) : Mammal::Mammal(d, r), fur_type{ d.fur_type } {}

const std::string Hare::getKind() const
{
	return "Hare";
}

Animal* Hare::breed(const Animal& partner) const
{
	return new Hare(*this, partner);
}

const std::string Hare::toString() const
{
	return Mammal::toString() + " Its fur type is " + fur_type + '.';
}
