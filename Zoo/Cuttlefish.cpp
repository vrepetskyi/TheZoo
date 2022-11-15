#include "Animal.h"
#include "Fish.h"
#include "Cuttlefish.h"
#include <cmath>
#include <string>

Cuttlefish::Cuttlefish(Reproductivity reproductivity) : Fish::Fish(1, reproductivity, 4), tentacles_number{ std::rand() % 3 + 9 } {}

Cuttlefish::Cuttlefish(const Cuttlefish& d, const Animal& r) : Fish::Fish(d, r), tentacles_number{ d.tentacles_number } {}

const std::string Cuttlefish::getKind() const
{
	return "Cuttlefish";
}

Animal* Cuttlefish::breed(const Animal& partner) const
{
	return new Cuttlefish(*this, partner);
}

const std::string Cuttlefish::toString() const
{
	return Fish::toString() + " It has " + std::to_string(tentacles_number) + " tentacles.";
}
